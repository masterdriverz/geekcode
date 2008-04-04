/*
 * Geek Code Generator v2
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#include "objs/appearance.h"
#include "objs/computers.h"
#include "objs/entertainment.h"
#include "objs/lifestyle.h"
#include "objs/politics.h"
#include "objs/type.h"

#define HIDDEN(ident, name)		{-1, 0, name, ident, 0},
#define INDEPENDANT(ident, name)	{-1, 1, name, ident, 0},
#define DEPENDANT(ident, name)		{-1, 1, name, ident, 1},
#define LINE_END			{0,  0, NULL,  NULL, 0}

static struct answer line1[] = {
	INDEPENDANT(gc_type, "type")
	INDEPENDANT(gc_dress, "dress")
	INDEPENDANT(gc_height, "height")
	INDEPENDANT(gc_weight, "weight")
	INDEPENDANT(gc_age, "age")
	INDEPENDANT(gc_computers, "computers")
	HIDDEN(gc_unix_type, "unix type")
	DEPENDANT(gc_unix, "unix")
	INDEPENDANT(gc_perl, "perl")
	INDEPENDANT(gc_linux, "linux")
	INDEPENDANT(gc_emacs, "emacs")
	INDEPENDANT(gc_www, "WWW")
	INDEPENDANT(gc_usenet, "usenet")
	INDEPENDANT(gc_oracle, "oracle")
	INDEPENDANT(gc_kibo, "kibo")
	INDEPENDANT(gc_windows, "windows")
	LINE_END
};

static struct answer line2[] = {
	INDEPENDANT(gc_os2, "OS2")
	INDEPENDANT(gc_mac, "mac")
	INDEPENDANT(gc_vms, "vms")
	INDEPENDANT(gc_social, "social")
	INDEPENDANT(gc_economic, "economic")
	INDEPENDANT(gc_cypher, "cypher")
	INDEPENDANT(gc_pgp, "PGP")
	INDEPENDANT(gc_startrek, "startrek")
	INDEPENDANT(gc_babylon5, "bablylon5")
	INDEPENDANT(gc_xfiles, "XFiles")
	INDEPENDANT(gc_rp, "roleplaying")
	INDEPENDANT(gc_television, "television")
	INDEPENDANT(gc_books, "books")
	INDEPENDANT(gc_dilbert, "dilbert")
	INDEPENDANT(gc_doom, "doom")
	LINE_END
};

static struct answer line3[] = {
	INDEPENDANT(gc_geekcode, "geekcode")
	INDEPENDANT(gc_education, "education")
	INDEPENDANT(gc_housing, "housing")
	INDEPENDANT(gc_relationships, "relationships")
	HIDDEN(gc_gender, "gender")
	DEPENDANT(gc_sex, "sex")
	LINE_END
};

struct answer *lines[] = {line1, line2, line3, NULL};
