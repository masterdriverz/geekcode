#ifndef _GC_COMPUTERS_H
#define _GC_COMPUTERS_H

#include "geekcode.h"

extern struct stuff computers[];
extern struct stuff unix_type[];
#define foo unix
#undef unix
extern struct stuff unix[];
#define unix foo
#undef foo
extern struct stuff computers[];
extern struct stuff perl[];
#define foo linux
#undef linux
extern struct stuff linux[];
#define linux foo
#undef foo
extern struct stuff emacs[];
extern struct stuff www[];
extern struct stuff usenet[];
extern struct stuff oracle[];
extern struct stuff kibo[];
extern struct stuff windows[];
extern struct stuff os2[];
extern struct stuff mac[];
extern struct stuff vms[];

#endif
