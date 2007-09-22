CFLAGS += -Wall
TARGET  = geekcode
CC     ?= gcc

LIBFILES = gc_appearance.o    \
           gc_computers.o     \
           gc_entertainment.o \
           gc_lifestyle.o     \
           gc_politics.o      \
           gc_type.o          \
           gc_consoleio.o     \
           gc_getanswer.o     \
           geekcode.o

all: $(TARGET)

%.o: %.c %.h geekcode.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(TARGET) $(LIBFILES)

geekcode: $(LIBFILES)
	$(CC) $(LDFLAGS) -o $(TARGET) $(LIBFILES)

install:
	install -m 755 geekcode /usr/local/bin
