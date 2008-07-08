#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "geekcode.h"
#include "lines.h"
#include "parse.h"

const char *parse_errors[] = {
	"Success",
	"Trailing text in data",
	"Missing alias",
	"Missing dependant",
	"Syntax error",
	"Unexpected EOF",
	"File error",
};

/*
 * Parses the contents of data into line.
 * Returns 0 on success, error code on failure.
 */
static enum parse_errors_t process_line(struct answer *line, char *data)
{
	char *last, *p;
	for ((p = strtok_r(data, " ", &last)); p && line->answer;
		(p = strtok_r(NULL, " ", &last)), line++) {

		int i;
		const struct elem *temp;
		char c=0;

		/* Skip lines we shouldn't display */
		while (!line->display)
			line++;

		/* Parse each 'element' in the text, put the value in the
		 * answer struct */
		for (temp = line->contents, i=0; temp[i].alias; i++) {
			char *n, buf[256];
			const char *s;

			/*
			 * If the line is dependant, iterate over the possible
			 * aliases it could be. If it's not, this loop will
			 * only be entered once.
			 */
			if (line->dependant) {
				if (sscanf(p, temp[i].alias, &c))
					snprintf(buf, sizeof(buf), temp[i].alias, c);
				else
					continue;
				s = (const char *)&buf;
			} else {
				s = temp[i].alias;
			}

			/* Kill those pesky newlines */
			n = strchr(p, '\n');
			if (n)
				*n = '\0';

			if (!strcmp(s, p))
				goto out;
		}
		return EALIAS;

out:
		line->answer = i+1;

		/* Set the answer of the dependant */
		if (c) {
			const struct elem *temp;
			int i;
			for (temp = (line-1)->contents, i = 0; temp->alias; temp++, i++)
				if (*(temp->alias) == c)
					goto found;
			return EDEPENDANT;

found:
			(line-1)->answer = i+1;
		}
	}

	/* There's something left! */
	if ((p && isalnum((unsigned char )*p)) || line->answer)
		return ETRAILING;
	return SUCCESS;
}

/*
 * Reads geekcode from in and initialises the structures in lines
 * appropriately.
 * Returns 0 on success, error code on failure.
 */
static int parse_header(FILE *in, unsigned *line_count)
{
	char data[1024];

	*line_count = 0;
	while (fgets(data, sizeof(data), in)) {
		(*line_count)++;
		if (strcmp(data, "-----BEGIN GEEK CODE BLOCK-----\n"))
			continue;
		/* Skip version line */
		/* XXX: Check version some way? */
		if (!fgets(data, sizeof(data), in))
			return -1;
		(*line_count)++;
		return 0;
	}
	return -1;
}

static int parse_code(FILE *in, unsigned *line_count)
{
	char data[1024];
	struct answer **cur_line = lines;

	while (fgets(data, sizeof(data), in)) {
		int ret;
		(*line_count)++;
		if (!strcmp(data, "------END GEEK CODE BLOCK------\n"))
			return 0;
		if (!*cur_line)
			return ESYNTAX;
		if ((ret = process_line(*cur_line, data)))
			return ret;
		cur_line++;
	}
	return -1;
}

unsigned read_code(FILE *in, unsigned *line_count)
{
	int ret;

	ret = parse_header(in, line_count);
	if (!ret)
		ret = parse_code(in, line_count);
	if (!ret)
		return 0;
	if (ret < 0) {
		if (ferror(in))
			return EFERROR;
		else
			return EEOF;
	}
	return ret;
}
