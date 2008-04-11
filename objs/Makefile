CFLAGS += -Wall -I../
CC     ?= gcc

OBJFILES = \
	appearance.o	\
	computers.o	\
	entertainment.o	\
	lifestyle.o	\
	politics.o	\
	type.o		\

HEADERS = \
	appearance.h	\
	computers.h	\
	entertainment.h	\
	lifestyle.h	\
	politics.h	\
	type.h		\

%.h: %.pre
	./generate_object_file.sh -h $< >$*.h

%.c: %.pre
	./generate_object_file.sh $< >$*.c

%.o: %.c %.h ../geekcode.h
	$(CC) $(CFLAGS) -c $< -o $*.o

all: $(OBJFILES) $(HEADERS)

clean:
	rm -f *.o *.c *.h
