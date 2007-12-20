#ifndef _GETANSWER_H
#define _GETANSWER_H

struct stuff *getcontent(const struct stuff2 *obj);
int getanswer(const char *name, int page_num,
		const struct stuff *objects,
		const char *additional);

#endif
