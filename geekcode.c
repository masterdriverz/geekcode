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

#include "geekcode.h"
#include "lines.h"
#include "getanswer.h"


#define not_geek(filename) do {			\
	fprintf(stderr,				\
"Error, file \"%s\" isn't geekcode\n",		\
		filename);			\
	exit(1);				\
} while (0);

#define file_error(filename, action) do {	\
	char error[256];			\
	snprintf(error, sizeof(error),		\
"Error while %s file \"%s\"", action, filename);\
	perror(error);				\
	exit(1);				\
} while (0);


/*
 * Parses the contents of data into line.
 * Returns 0 on success, -1 on failure, and sets errno appropriately.
 */
int process_line(struct stuff2 *line, char *data)
{
	char *last, *p;
	for ((p = strtok_r(data, " ", &last)); p && line->answer;
		(p = strtok_r(NULL, " ", &last)), line++) {

		int i;
		struct stuff *temp;
		char c=0;

		while (!line->display)
			line++;

		for (temp = line->contents, i=0; temp[i].alias; i++) {
			char *n, buf[256];
			if (line->dependant) {
				if (sscanf(p, temp[i].alias, &c))
					snprintf(buf, sizeof(buf), temp[i].alias, c);
				else
					continue;
			} else {
				strncpy(buf, temp[i].alias, sizeof(buf)-1);
				buf[sizeof(buf)-1] = '\0';
			}
			n = strchr(p, '\n');
			if (n)
				*n = '\0';
			if (!strcmp(buf, p))
				goto out;
		}
		errno = EINVAL;
		return -1;
out:
		line->answer = i;
		if (c) {
			struct stuff *temp;
			int i;
			for (temp = (line-1)->contents, i = 1; temp->alias; temp++, i++)
				if (*(temp->alias) == c)
					goto found;
			errno = EINVAL;
			return -1;
found:
			(line-1)->answer = i;
		}
	}
	if ((p && isalnum((unsigned char )*p)) || line->answer) {
		errno = EINVAL;
		return -1;
	}
	return 0;
}

/*
 * Reads geekcode from in and initialises the structures in lines
 * appropriately.
 * Returns 0 on success, -1 on failure.
 */
int read_code(FILE *in)
{
	char data[1024];
	struct stuff2 **cur_line = lines;

	while (fgets(data, sizeof(data), in)) {
		if (strcmp(data, "-----BEGIN GEEK CODE BLOCK-----\n"))
			continue;
		/* Skip version line */
		if (!fgets(data, sizeof(data), in))
			return -1;
		goto next_loop;
	}
	/*
	 * We didn't skip this, so fgets failed before we reached the start of
	 * a GEEK CODE block.
	 * */
	return -1;
next_loop:
	while (fgets(data, sizeof(data), in)) {
		if (!strcmp(data, "------END GEEK CODE BLOCK------\n"))
			break;
		if (process_line(*cur_line, data)) {
			perror("There was an error reading a line");
			exit(1);
		}
		cur_line++;
		if (!*cur_line)
			break;
	}
	return 0;
}

void create_code(void)
{
	struct stuff2 **cur_line;
	int page_num=1;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct stuff2 *cur_question;
		for (cur_question = *cur_line;
				cur_question->answer;
				cur_question++, page_num++) {
			char *aux_string=NULL;
			if (cur_question->dependant) {
				struct stuff *aux = getcontent(cur_question-1);
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

void output_code(FILE *out)
{
	struct stuff2 **cur_line;

	fprintf(out, "-----BEGIN GEEK CODE BLOCK-----\n");
	fprintf(out, "Version: 3.12\n");

	for (cur_line = lines; *cur_line; cur_line++) {
		struct stuff2 *cur_question;
		for (cur_question = *cur_line;
				cur_question->answer;
				cur_question++) {
			struct stuff *content;
			if (!cur_question->display)
				continue;
			content = getcontent(cur_question);
			if (!content) {
				fprintf(stderr, "\n%s\n", cur_question->name);
				perror("There was an error getting an alias");
				exit(1);
			}
			if (cur_question->dependant) {
				struct stuff *aux = getcontent(cur_question-1);
				if (!aux) {
					perror(NULL);
					exit(1);
				}
				fprintf(out, content->alias, *aux->alias);
			} else {
				fputs(content->alias, out);
			}
			fprintf(out, " ");
		}
		fprintf(out, "\n");
	}

	fprintf(out, "\n");
	fprintf(out, "------END GEEK CODE BLOCK------\n");
}

void output_answers(FILE *out)
{
	struct stuff2 **cur_line;
	for (cur_line = lines; *cur_line; cur_line++) {
		struct stuff2 *cur_question;
		for (cur_question = *cur_line; cur_question->answer; cur_question++) {
			struct stuff *content = getcontent(cur_question);
			if (!content) {
				perror("There was an error getting an answer");
				exit(1);
			}
			fprintf(out, "%s: %s\n",
				cur_question->name, content->comment);
		}
	}
}

const char usage_str[] = "\
./geekcode [ --read || --write [ --output=file ] ] <file>\n\
  --read\n\
     Translate a geekcode file (reads from stdin if no files given).\n\
  --write\n\
     Interactively input a geekcode (default).\n\
  --output <file>\n\
     (Only applicable with --write.)\n\
     Write the final geekcode to file (but still write the questions to stdout).\
";

inline void usage(FILE *out)
{
	fputs(usage_str, out);
}

FILE *open_file(const char *filename, const char *mode)
{
	FILE *f;
	struct stat fileinfo;
	if (stat(filename, &fileinfo) == -1)
		file_error(filename, "checking");

	if (S_ISREG(fileinfo.st_mode) != 1){
		fprintf(stderr, "Error, file \"%s\" isn't a regular file\n",
			filename);
		exit(1);
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
	struct option long_options[] = {
		{"read",	no_argument,		NULL,	'r'},
		{"write",	no_argument,		NULL,	'w'},
		{"output",	required_argument,	NULL,	'o'},
		{"help",	no_argument,		NULL,	'h'},
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
		default:
			usage(stderr);
			return -1;
		}
	}
	if (output && read) {
		fprintf(stderr, "It only makes sense to use --output with --write.\n");
		usage(stderr);
		return -1;
	}
	if (read) {
		FILE *f=NULL;
		if (write) {
			fprintf(stderr, "Can't read and write a file at the same time.\n");
			usage(stderr);
			return -1;
		}
		for (index = optind; index < argc; index++) {
			f = open_file(argv[index], "r");
			read_code(f);
			if (fclose(f))
				file_error(argv[index], "closing");
			output_answers(stdout);
			printf("\n");
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
			fprintf(stderr, "--write takes no arguments\n");
			usage(stderr);
			return -1;
		}
		create_code();
		output_code(f);
	}
	return 0;
}
