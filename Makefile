CFLAGS += -Wall -Iobjs/ -I.
TARGET  = geekcode
PREFIX  = /usr/local
BINDIR  = $(PREFIX)/bin

LIBFILES = \
	getanswer.o	\
	lines.o		\
	debug.o		\
	geekcode.o

all: $(TARGET)

lines.o: lines.c geekcode.h objs

%.o: %.c %.h geekcode.h
	$(CC) -c -o $@ $< $(CFLAGS)

objs: force_look
	cd objs; $(MAKE) $(MFLAGS)

clean:
	cd objs; $(MAKE) $(MFLAGS) clean
	$(RM) -f $(TARGET) $(LIBFILES)

geekcode: $(LIBFILES) objs
	$(CC) $(LDFLAGS) -o $(TARGET) $(LIBFILES) objs/*.o

install:
	$(INSTALL) -m 755 $(TARGET) $(BINDIR)

force_look:
	true
