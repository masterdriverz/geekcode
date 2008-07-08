enum parse_errors_t {
	SUCCESS = 0,
	ETRAILING,
	EALIAS,
	EDEPENDANT,
	ESYNTAX,
	EEOF,
	EFERROR,
};

const char *parse_errors[];
unsigned read_code(FILE *in, unsigned *line_count);
