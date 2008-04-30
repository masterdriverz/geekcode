/*
 * Geek Code Generator v2
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * Based on code by Chris Gushue <chris@blackplasma.net>
 * License: GPL2
 */

#define _GNU_SOURCE
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "geekcode.h"
#include "getanswer.h"

#define eof_error() do {		\
	fputs("\nGot EOF on stdin, aborting...\n", \
		stderr);		\
	exit(1);			\
} while (0);

/* Prints a single page (answer). Returns the number of elems printed */
static unsigned int print_page(const char *name, int page_num,
		const struct elem *objects,
		const char *additional)
{
	unsigned int i;
	printf("\nPage %i of %i: %s\n", page_num, PAGES, name);
	puts("===============================================================================");
	for (i = 0; objects[i].comment; i++) {
		const char *alias = objects[i].alias;
		if (additional) {
			/* The %c is replaced by a char and a NULL,
			 * hence no +1 */
			char *s = malloc(strlen(objects[i].alias));
			if (!s) {
				perror(NULL);
				exit(-1);
			}
			sprintf(s, objects[i].alias, *additional);
			alias = s;
		}
		printf("%2d %-5s %s\n", i+1, alias, objects[i].comment);
		if (additional)
			free((void *)alias);
	}
	return i;
}

int getanswer(const char *name, int page_num,
		const struct elem *objects,
		const char *additional)
{
	static char *p = NULL;
	static size_t n;
	int max;
	char *s;
	char *endptr;
	long val;

print:
	max = print_page(name, page_num, objects, additional);

	putc('\n', stdout);
foo:
	/*
	if (selection != -1)
		fputs(stdout, "Invalid option: ");
		*/
	printf("Enter your %s code number here [q to quit, 0 to repeat]: ", name);
	if (getline(&p, &n, stdin) == -1) {
		if (feof(stdin))
			eof_error();
		perror(NULL);
		exit(1);
	}
	s = p;
	errno = 0;
	val = strtol(s, &endptr, 10);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
		|| (errno != 0 && val == 0)) {
		perror("strtol");
		exit(1);
	}

	if (endptr == s) {
		fprintf(stderr, "No digits were found\n");
		exit(1);
	}

		while (*s == ' ')
			s++;
		if (*s == 'q' || *s == 'Q')
			exit(0);
	if (val > max)
		goto foo;
	if (val == 0)
		goto print;

	return (int)val;
}
