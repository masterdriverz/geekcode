CFLAGS += -Wall -Iobjs/ -I.
TARGET  = geekcode
PREFIX  = /usr/local
BINDIR  = $(PREFIX)/bin

LIBFILES = \
	debug.o		\
	getanswer.o	\
	lines.o		\
	parse.o		\
	geekcode.o

all: $(TARGET)

lines.o: lines.c geekcode.h objs

%.o: %.c %.h geekcode.h
	$(CC) -c -o $@ $< $(CFLAGS)

objs: force_look
	cd objs; $(MAKE) $(MFLAGS)

clean_obj:
	cd objs; $(MAKE) $(MFLAGS) clean

clean_src:
	$(RM) -f $(TARGET) $(LIBFILES)

clean: clean_src clean_obj

geekcode: $(LIBFILES) objs
	$(CC) $(LDFLAGS) -o $(TARGET) $(LIBFILES) objs/*.o

install:
	$(INSTALL) -m 755 $(TARGET) $(BINDIR)

force_look:
	true
