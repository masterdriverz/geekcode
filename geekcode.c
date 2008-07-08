/*
 * Geek Code Generator v2
 * Copyright (C) 1999-2003 Chris Gushue <chris@blackplasma.net>
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#include <errno.h>
#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

#include "getanswer.h"
#include "debug.h"
#include "lines.h"
#include "parse.h"
#include "geekcode.h"


static void output_answers(FILE *out);
static void file_error(const char *filename, const char *action)
{
	char error[256];
	snprintf(error, sizeof(error), "Error while %s file \"%s\"",
		action, filename);
	perror(error);
	exit(1);
}

/*
 * Wrapper around getcontent, exiting on failure and printing a useful
 * message. If format is non-NULL, uses printf format semantics.
 */
_printf(2, 3)
static const struct elem *xgetcontent(const struct answer *obj,
		const char *format, ...)
{
	const struct elem *content;
	va_list ap;
	va_start(ap, format);
	content = getcontent(obj);
	if (!content) {
		if (format)
			vfprintf(stderr, format, ap);
		else
			fputs("Error getting content\n", stderr);
		print_answer_struct(obj);
		exit(1);
	}
	return content;
}

static void run_code(const char *filename, FILE *in)
{
	unsigned ret, line_count;
	ret = read_code(in, &line_count);
	if (ret) {
		fprintf(stderr, "Error '%s' in file %s, line %u\n", parse_errors[ret], filename, line_count);
		exit(1);
	}
	output_answers(stdout);
}

/* Loop over lines, reading in answers from stdin */
static void create_code(void)
{
	struct answer **cur_line;
	int page_num=1;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct answer *cur_question;
		for (cur_question = *cur_line;
				cur_question->answer;
				cur_question++, page_num++) {
			const char *aux_string=NULL;
			if (cur_question->dependant) {
				const struct elem *aux = xgetcontent(cur_question-1,
					"function: %s; line %d\n", __func__, __LINE__);
				aux_string = aux->alias;
			}
			cur_question->answer =
				getanswer(cur_question->name, page_num,
					cur_question->contents, aux_string);
		}
	}
}

/* Outputs the geekcode stored in lines to out */
static void output_code(FILE *out)
{
	struct answer **cur_line;

	fputs("-----BEGIN GEEK CODE BLOCK-----\n", out);
	fputs("Version: 3.12\n", out);

	for (cur_line = lines; *cur_line; cur_line++) {
		const struct answer *cur_question;
		for (cur_question = *cur_line;
				cur_question->answer;
				cur_question++) {
			const struct elem *content;
			if (!cur_question->display)
				continue;
			content = xgetcontent(cur_question,
				"\nThere was an error getting an alias (%s)\n",
				cur_question->name);
			if (cur_question->dependant) {
				const struct elem *aux =
					xgetcontent(cur_question-1, "There was an error getting content\n");
				fprintf(out, content->alias, *aux->alias);
			} else {
				fputs(content->alias, out);
			}
			putc(' ', out);
		}
		putc('\n', out);
	}

	fputs("------END GEEK CODE BLOCK------\n", out);
}

static void output_answers(FILE *out)
{
	struct answer **cur_line;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct answer *cur_question;
		for (cur_question = *cur_line; cur_question->answer; cur_question++) {
			const struct elem *content =
				xgetcontent(cur_question, "There was an error getting an answer\n");
			fprintf(out, "%s: %s\n",
				cur_question->name, content->comment);
		}
	}
}

static void list_sections(void)
{
	struct answer **cur_line;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct answer *cur_question;
		for (cur_question = *cur_line; cur_question->answer; cur_question++)
			puts(cur_question->name);
	}
}


static const char usage_str[] = "\
./geekcode [ --list || --read || --write [ --output=file ] || --version ] <file>\n\
" VERSIONSTR "\n\n\
  --list\n\
     List the sections in geekcode.\n\
  --read\n\
     Translate a geekcode file (reads from stdin if no files given).\n\
  --write\n\
     Interactively input a geekcode (default).\n\
  --output <file>\n\
     (Only applicable with --write.)\n\
     Write the final geekcode to file (but still write the questions to stdout).\n\
";
static const char version_str[] = VERSIONSTR;

static inline void usage(FILE *out)
{
	fputs(usage_str, out);
}

static inline void version(void)
{
	puts(version_str);
}

/*
 * Opens filename with mode mode, checking it's a regular file if it's being
 * opened for reading and checking the open succeeds. If either of these fails
 * it exit(1)'s, never returning NULL.
 */
static FILE *open_file(const char *filename, const char *mode)
{
	FILE *f;

	/* Check filename is the type of file we want */
	if (mode[0] == 'r') {
		struct stat fileinfo;
		if (stat(filename, &fileinfo) == -1)
			file_error(filename, "checking");

		if (!S_ISREG(fileinfo.st_mode)) {
			fprintf(stderr, "Error, file \"%s\" isn't a regular file\n",
				filename);
			exit(1);
		}
	}

	f = fopen(filename, mode);
	if (!f)
		file_error(filename, "opening");
	return f;
}

int main(int argc, char **argv)
{
	char *outfile=NULL;
	int read=0, write=0, output=0, list=0, c, index;
	const struct option long_options[] = {
		{"list",	no_argument,		NULL,	'l'},
		{"read",	no_argument,		NULL,	'r'},
		{"write",	no_argument,		NULL,	'w'},
		{"output",	required_argument,	NULL,	'o'},
		{"help",	no_argument,		NULL,	'h'},
		{"version",	no_argument,		NULL,	'v'},
		{NULL, 0, NULL, 0}
	};
	while ((c = getopt_long(argc, argv, "lrwho:", long_options, &index)) != -1) {
		switch (c) {
		case 'l':
			list = 1;
			break;
		case 'r':
			read = 1;
			break;
		case 'w':
			write = 1;
			break;
		case 'h':
			usage(stdout);
			return 0;
		case 'o':
			output = 1;
			outfile = optarg;
			break;
		case 'v':
			version();
			return 0;
		default:
			usage(stderr);
			return -1;
		}
	}
	if (write+read+list > 1) {
		fputs("Conflicting actions given simultaneously.\n", stderr);
		usage(stderr);
		return -1;
	} else if (!write+read+list) {
		write = 1;
	}
	if (output && !write) {
		fputs("It only makes sense to use --output with --write.\n", stderr);
		usage(stderr);
		return 1;
	}
	if (list) {
		list_sections();
	} else if (read) {
		FILE *f=NULL;
		for (index = optind; index < argc; index++) {
			f = open_file(argv[index], "r");
			run_code(argv[index], f);
			if (fclose(f))
				file_error(argv[index], "closing");
		}
		/* If we haven't opened anything, use stdin */
		if (!f)
			run_code("stdin", stdin);
	} else {
		FILE *f;
		if (outfile)
			f = open_file(outfile, "w");
		else
			f = stdout;
		if (optind < argc) {
			fputs("--write takes no arguments\n", stderr);
			usage(stderr);
			return -1;
		}
		create_code();
		output_code(f);
	}
	return 0;
}
