#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geekcode.h"

/* Return the amount of character c's in s */
static int count(char *s, char c)
{
	int i=0;
	while (*s) {
		if (*s == c)
			i++;
		s++;
	}
	return i;
}

static char *make_spaces(int amount)
{
	/* Cache? */
	char *s=malloc(amount);
	if (!s)
		return NULL;
	memset(s, ' ', amount);
	return s;
}

int getanswer(char *name, int page_num, struct stuff *objects, char *additional)
{
	int selection=99, num_count, i, line_count, c, overflowed=0;
	char *spaces=make_spaces(66-strlen(name));

	do {
		num_count = MAX_LINES;
		line_count = 0;
		clearscreen();

		printf("%s%sPage %2i of %i\n", name, spaces, PAGES-(PAGES-page_num), PAGES);
		printf("===============================================================================\n");
		for (i=0; objects[i].num; i++) {
			char *s=objects[i].alias;
			if (!num_count) {
				printf("Press any key to continue: ");
				if (getchar() == EOF)
					eof_error();
				num_count = MAX_LINES;
				overflowed = 1;
			}
			if (additional) {
				s = malloc(strlen(s)+strlen(additional)+1);
				if (!s) {
					perror(NULL);
					exit(-1);
				}
				sprintf(s, objects[i].alias, additional);
			}
			printf("%2d %-5s %s\n", objects[i].num, s, objects[i].comment);
			num_count -= count(objects[i].comment, '\n')+1;
			if (additional)
				free(s);
			line_count++;
		}
		if (!overflowed)
			while (num_count-- > 0)
				printf("\n");
		printf("Enter your %s code number here [0 to quit]: ", name);
		c = scanf("%d", &selection);

		if (c == EOF)
			eof_error();

		clear_kb();
	} while (selection < 0 || selection > line_count || c != 1);

	free(spaces);
	if (selection == 0)
		exit(1);
	else
		return selection;
}

char *getalias(struct stuff2 *obj)
{
	struct stuff *temp=obj->contents;
	if (!obj->answer || obj->answer == -1) {
		errno = EINVAL;
		return NULL;
	}
	while (temp->num) {
		if (obj->answer == temp->num)
			goto out;
		temp++;
	}
	/* We should never get here */
	errno = EINVAL;
	return NULL;
out:
	return temp->alias;
}

char *getcomment(struct stuff2 *obj)
{
	struct stuff *temp=obj->contents;
	if (!obj->answer || obj->answer == -1) {
		errno = EINVAL;
		return NULL;
	}
	while (temp->num) {
		if (obj->answer == temp->num)
			goto out;
		temp++;
	}
	/* We should never get here */
	errno = EINVAL;
	return NULL;
out:
	return temp->comment;
}
