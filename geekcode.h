/*
 geekcode.h - GeekCode Global Header File

 Geek Code Generator v1.7.3 - Generates your geek code
 Copyright (C) 1999-2003 Chris Gushue <chris@blackplasma.net>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __INCLUDED_GEEKCODE_H__
#define __INCLUDED_GEEKCODE_H__


#define VERSION "1.7.3" /* Added in v1.2 */

#include <stdlib.h>
#define SENTINEL {0, NULL, NULL}

#define PAGES 36
#define MAX_LINES 21

struct stuff {
	int num;
	char *alias, *comment;
};

struct stuff2 {
	int answer, display;
	char *name;
	struct stuff *contents;
	int dependant;
};

char *getalias(struct stuff2 *obj);
char *getcomment(struct stuff2 *obj);

#define eof_error() do {		\
	fprintf(stderr,			\
"\n\nGot EOF on stdin, aborting...\n");	\
	exit(1);			\
} while (0);

int getanswer(char *name, int page_num, struct stuff *objects, char *additional);

void show_geekcode(int x);                /* Modified in v1.2 */
void write_geekcode(int x);		  /* Added in v1.7 */

void clear_kb(void);                      /* Added in v1.3 */

/* Console I/O - gc_consoleio.c */
void clearscreen(void);

#endif /* __INCLUDED_GEEKCODE_H__ */
