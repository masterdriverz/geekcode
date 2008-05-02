/*
 * Geek Code Generator v2
 * Copyright (C) 1999-2003 Chris Gushue <chris@blackplasma.net>
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#ifndef _GEEKCODE_H
#define _GEEKCODE_H

#include <stdlib.h>

#define VERSION 2
#define _str(x) #x
#define str(x) _str(x)
#define VERSIONSTR "Geekcode version v" str(VERSION)

#define _printf(a, b) __attribute__((format(printf, a, b)))

#define PAGES 37
#define MAX_LINES 21

struct elem {
	const char *alias, *comment;
};

struct answer {
	int answer, display, dependant;
	const char *name;
	const struct elem *contents;
};

#define SENTINEL {NULL, NULL}

#endif /* _GEEKCODE_H */
