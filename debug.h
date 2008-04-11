#include "geekcode.h"

#ifdef DEBUG
void print_elem_struct(const struct elem *e);
void print_answer_struct(const struct answer *a);
#else
static inline void print_elem_struct(const struct elem *e) { }
static inline void print_answer_struct(const struct answer *a) { }
#endif
