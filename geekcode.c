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

#include "lines.h"
#include "debug.h"
#include "getanswer.h"
#include "geekcode.h"


#define not_geek(filename) do {			\
	fprintf(stderr,				\
"Error, file \"%s\" isn't geekcode\n",		\
		filename);			\
	exit(1);				\
} while (0)

#define file_error(filename, action) do {	\
	char error[256];			\
	snprintf(error, sizeof(error),		\
"Error while %s file \"%s\"", action, filename);\
	perror(error);				\
	exit(1);				\
} while (0)


enum line_errors {
	TRAILING = 1, /* Trailing text in data */
	M_ALIAS, /* Missing alias */
	M_DEPENDANT, /* Missing dependant */
};

/*
 * Parses the contents of data into line.
 * Returns 0 on success, error code on failure.
 */
static unsigned int process_line(struct answer *line, char *data)
{
	char *last, *p;
	for ((p = strtok_r(data, " ", &last)); p && line->answer;
		(p = strtok_r(NULL, " ", &last)), line++) {

		int i;
		const struct elem *temp;
		char c=0;

		/* Skip lines we shouldn't display */
		while (!line->display)
			line++;

		/*
		 * XXX: This whole section is ick. It copies strings A LOT,
		 *      which it shouldn't.
		 */
		/* Parse each 'element' in the text, put the value in the
		 * line2 struct */
		for (temp = line->contents, i=0; temp[i].alias; i++) {
			char *n, buf[256];

			/* Work out the dependant thing */
			if (line->dependant) {
				if (sscanf(p, temp[i].alias, &c))
					/* Ick. */
					snprintf(buf, sizeof(buf), temp[i].alias, c);
				else
					continue;
			} else {
				/* Ick. */
				/* Just copy the string to buf if it's not dependant */
				strncpy(buf, temp[i].alias, sizeof(buf)-1);
				buf[sizeof(buf)-1] = '\0';
			}

			/* Kill those pesky newlines */
			n = strchr(p, '\n');
			if (n)
				*n = '\0';

			if (!strcmp(buf, p))
				goto out;
		}
		return M_ALIAS;

out:
		line->answer = i;

		/* Set the answer of the dependant */
		if (c) {
			const struct elem *temp;
			int i;
			for (temp = (line-1)->contents, i = 1; temp->alias; temp++, i++)
				if (*(temp->alias) == c)
					goto found;
			return M_DEPENDANT;

found:
			(line-1)->answer = i;
		}
	}

	/* There's something left! */
	if ((p && isalnum((unsigned char )*p)) || line->answer)
		return TRAILING;
	return 0;
}

/*
 * Reads geekcode from in and initialises the structures in lines
 * appropriately.
 * Returns 0 on success, 1 on parsing failure, 2 on file error.
 */
static unsigned int read_code(FILE *in)
{
	char data[1024];
	struct answer **cur_line = lines;

	while (fgets(data, sizeof(data), in)) {
		if (strcmp(data, "-----BEGIN GEEK CODE BLOCK-----\n"))
			continue;
		/* Skip version line */
		if (!fgets(data, sizeof(data), in))
			return 2;
		goto next_loop;
	}
	/* fgets failed */
	return 2;
next_loop:
	while (fgets(data, sizeof(data), in)) {
		if (!strcmp(data, "------END GEEK CODE BLOCK------\n"))
			break;
		if (process_line(*cur_line, data)) {
			puts("There was an error reading a line");
			return 1;
		}
		cur_line++;
		if (!*cur_line)
			break;
	}
	return 0;
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
				const struct elem *aux = getcontent(cur_question-1);
				if (!aux) {
					perror(NULL);
					exit(1);
				}
				aux_string = aux->alias;
			}
			cur_question->answer =
				getanswer(cur_question->name, page_num,
					cur_question->contents, aux_string);
		}
	}
}

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
			content = getcontent(cur_question);
			if (!content) {
				fprintf(stderr, "\n%s\n", cur_question->name);
				perror("There was an error getting an alias");
				exit(1);
			}
			if (cur_question->dependant) {
				const struct elem *aux = getcontent(cur_question-1);
				if (!aux) {
					perror(NULL);
					exit(1);
				}
				fprintf(out, content->alias, *aux->alias);
			} else {
				fputs(content->alias, out);
			}
			putc(' ', out);
		}
		putc('\n', out);
	}

	fputs("\n------END GEEK CODE BLOCK------\n", out);
}

static void output_answers(FILE *out)
{
	struct answer **cur_line;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct answer *cur_question;
		for (cur_question = *cur_line; cur_question->answer; cur_question++) {
			const struct elem *content = getcontent(cur_question);
			if (!content) {
				perror("There was an error getting an answer");
				print_answer_struct(cur_question);
				exit(1);
			}
			fprintf(out, "%s: %s\n",
				cur_question->name, content->comment);
		}
	}
}

static const char usage_str[] = "\
./geekcode [ --read || --write [ --output=file ] || --version ] <file>\n\
" VERSIONSTR "\n\n\
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

static FILE *open_file(const char *filename, const char *mode)
{
	FILE *f;

	/* Check filename is the type of file we want */
	/* XXX: This is icky */
	if (mode[0] == 'r' && mode[1] == '\0') {
		struct stat fileinfo;
		if (stat(filename, &fileinfo) == -1)
			file_error(filename, "checking");

		if (S_ISREG(fileinfo.st_mode) != 1){
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
	int read=0, write=0, output=0, c, index;
	const struct option long_options[] = {
		{"read",	no_argument,		NULL,	'r'},
		{"write",	no_argument,		NULL,	'w'},
		{"output",	required_argument,	NULL,	'o'},
		{"help",	no_argument,		NULL,	'h'},
		{"version",	no_argument,		NULL,	'v'},
		{NULL, 0, NULL, 0}
	};
	while ((c = getopt_long(argc, argv, "rwho:", long_options, &index)) != -1) {
		switch (c) {
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
	if (output && read) {
		fputs("It only makes sense to use --output with --write.\n", stderr);
		usage(stderr);
		return -1;
	}
	if (read) {
		FILE *f=NULL;
		if (write) {
			fputs("Can't read and write a file at the same time.\n", stderr);
			usage(stderr);
			return -1;
		}
		for (index = optind; index < argc; index++) {
			int ret;
			f = open_file(argv[index], "r");
			if ((ret = read_code(f)) != 0) {
				/* If 1, we've already output an error message */
				if (ret == 2) {
					if (feof(f))
						fputs("Unexpected EOF.\n", stderr);
					else
						file_error(argv[index], "reading");
				}
				return ret;
			}
			if (fclose(f))
				file_error(argv[index], "closing");
			output_answers(stdout);
			putc('\n', stdout);
		}
		/* If we haven't opened anything, use stdin */
		if (!f) {
			read_code(stdin);
			output_answers(stdout);
		}
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
