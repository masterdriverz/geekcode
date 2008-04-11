#include <stdio.h>
#include "geekcode.h"
#include "getanswer.h"
#include "debug.h"

#ifdef DEBUG
void print_elem_struct(const struct elem *e)
{
	printf("Alias '%s': '%s'\n", e->alias, e->comment);
}

void print_answer_struct(const struct answer *a)
{
	printf("struct answer %s (%p): "
		"answer: %d; is%s hidden; is%s dependant\n",
		a->name, a, a->answer,
		a->display ? " not" : "",
		a->dependant ? " not" : "");
	if (a->answer > 0) {
		printf("current elem: ");
		print_elem_struct(getcontent(a));
	}
}
#endif
