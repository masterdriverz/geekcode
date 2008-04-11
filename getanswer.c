/*
 * Geek Code Generator v2
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * Based on code by Chris Gushue <chris@blackplasma.net>
 * License: GPL2
 */

#include <errno.h>
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

/*
 * Empties keyboard input buffer until it reaches a newline.
 * Returns 1 on EOF, 0 otherwise.
 */
static int clear_kb(void)
{
	int c;
	while ((c = getchar()) != '\n')
		if (c == EOF)
			return 1;
	return 0;
}

int getanswer(const char *name, int page_num,
		const struct elem *objects,
		const char *additional)
{
	int selection, i;

	do {
		printf("\nPage %2i of %i: %s\n", page_num, PAGES, name);
		puts("===============================================================================");
		for (i=0; objects[i].comment; i++) {
			const char *alias = objects[i].alias;
			if (additional) {
				char *s = malloc(strlen(objects[i].alias)+strlen(additional)+1);
				if (!s) {
					perror(NULL);
					exit(-1);
				}
				sprintf(s, objects[i].alias, additional);
				alias = s;
			}
			printf("%2d %-5s %s\n", i+1, alias, objects[i].comment);
			if (additional)
				free((void *)alias);
		}
		printf("\nEnter your %s code number here [0 to quit]: ", name);
		if (scanf("%d", &selection) == EOF)
			eof_error();

		if (clear_kb())
			eof_error();
	} while (selection < 0 || selection > i);

	if (selection == 0)
		exit(0);
	else
		return selection;
}

const struct elem *getcontent(const struct answer *obj)
{
	if (obj->answer <= 0)
		return NULL;

	return &obj->contents[obj->answer-1];
}
