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

static char *make_spaces(unsigned int amount)
{
	static char s[67];
	static int prev=-1;

	if (prev == -1) {
		memset(s, ' ', amount);
		s[66] = '\0';
	} else if (amount == prev) {
		return s;
	} else {
		s[prev] = ' ';
	}
#ifdef DEBUG
	printf("\nprev: %d\namount: %d\nspaces: '%s'\n",
		prev, amount, s);
#endif

	prev = amount;
	s[amount] = '\0';

#ifdef DEBUG
	printf("len: %d\n", strlen(s));
#endif
	return s;
}

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
	char *spaces=make_spaces(66-strlen(name));

	do {
		printf("%s%sPage %2i of %i\n", name, spaces, page_num, PAGES);
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
