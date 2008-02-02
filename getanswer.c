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
#include "consoleio.h"

#define eof_error() do {		\
	fputs("\nGot EOF on stdin, aborting...\n", \
		stderr);		\
	exit(1);			\
} while (0);

/* Return the amount of character c's in s */
static int count(const char *s, char c)
{
	int i=0;
	for (; *s; s++)
		if (*s == c)
			i++;
	return i;
}

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

int getanswer(const char *name, int page_num,
		const struct stuff *objects,
		const char *additional)
{
	int selection, line_count;
	char *spaces=make_spaces(66-strlen(name));

	do {
		int i, num_count=MAX_LINES, overflowed=0;
		line_count = 0;
		clearscreen();

		printf("%s%sPage %2i of %i\n", name, spaces, page_num, PAGES);
		puts("===============================================================================");
		for (i=0; objects[i].comment; i++) {
			const char *alias = objects[i].alias;
			if (!num_count) {
				printf("Press enter to continue: ");
				if (clear_kb())
					eof_error();
				num_count = MAX_LINES;
				overflowed = 1;
			}
			if (additional) {
				char *s = malloc(strlen(s)+strlen(additional)+1);
				if (!s) {
					perror(NULL);
					exit(-1);
				}
				sprintf(s, objects[i].alias, additional);
				alias = s;
			}
			printf("%2d %-5s %s\n", i+1, alias, objects[i].comment);
			num_count -= count(objects[i].comment, '\n')+1;
			if (additional)
				free((void *)alias);
			line_count++;
		}
		if (!overflowed)
			while (num_count-- > 0)
				printf("\n");
		printf("Enter your %s code number here [0 to quit]: ", name);
		if (scanf("%d", &selection) == EOF)
			eof_error();

		if (clear_kb())
			eof_error();
	} while (selection < 0 || selection > line_count);

	if (selection == 0)
		exit(0);
	else
		return selection;
}

const struct stuff *getcontent(const struct stuff2 *obj)
{
	if (obj->answer <= 0)
		return NULL;

	return &obj->contents[obj->answer-1];
}
