CFLAGS += -Wall -Iobjs/ -I.
TARGET  = geekcode
CC     ?= gcc
PREFIX ?= /usr/local

LIBFILES = \
	consoleio.o	\
	getanswer.o	\
	lines.o		\
	geekcode.o

all: $(TARGET)

lines.o: lines.c geekcode.h objs

%.o: %.c %.h geekcode.h
	$(CC) -c -o $@ $< $(CFLAGS)

objs: force_look
	cd objs; $(MAKE) $(MFLAGS)

clean:
	cd objs; $(MAKE) $(MFLAGS) clean
	rm -f $(TARGET) *.o

geekcode: $(LIBFILES) objs
	$(CC) $(LDFLAGS) -o $(TARGET) $(LIBFILES) objs/*.o

install:
	install -m 755 geekcode $(PREFIX)/bin

force_look:
	true
