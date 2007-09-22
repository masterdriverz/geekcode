#ifndef _GC_GETANSWER_H
#define _GC_GETANSWER_H

#define eof_error() do {		\
	fprintf(stderr,			\
"\n\nGot EOF on stdin, aborting...\n");	\
	exit(1);			\
} while (0);

struct stuff *getcontent(struct stuff2 *obj);
int getanswer(char *name, int page_num, struct stuff *objects, char *additional);

#endif
