#ifndef _GETANSWER_H
#define _GETANSWER_H

#include "geekcode.h"

int getanswer(const char *name, int page_num,
		const struct elem *objects,
		const char *additional);

static inline const struct elem *getcontent(const struct answer *obj)
{
	if (obj->answer <= 0)
		return NULL;

	return &obj->contents[obj->answer-1];
}

#endif
