/*
 * Geek Code Generator v2
 * Copyright (C) 1999-2003 Chris Gushue <chris@blackplasma.net>
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#ifndef __INCLUDED_GEEKCODE_H__
#define __INCLUDED_GEEKCODE_H__

#include <stdlib.h>

#define VERSION "1.7.3"
#define PAGES 36
#define MAX_LINES 21

struct stuff {
	char *alias, *comment;
};

struct stuff2 {
	int answer, display;
	char *name;
	const struct stuff *contents;
	int dependant;
};

#define SENTINEL {NULL, NULL}

#endif /* __INCLUDED_GEEKCODE_H__ */
