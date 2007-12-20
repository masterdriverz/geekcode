CFLAGS += -Wall -Iobjs/ -I.
TARGET  = geekcode
CC     ?= gcc
PREFIX ?= /usr/local

LIBFILES = \
	gc_consoleio.o		\
	gc_getanswer.o		\
	gc_lines.o		\
	geekcode.o

all: $(TARGET)

gc_lines.o: gc_lines.c geekcode.h objs

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
