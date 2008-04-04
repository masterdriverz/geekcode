#ifndef _GETANSWER_H
#define _GETANSWER_H

#include "geekcode.h"

const struct elem *getcontent(const struct answer *obj);
int getanswer(const char *name, int page_num,
		const struct elem *objects,
		const char *additional);

#endif
