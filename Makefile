#WARNINGS = -D_FORTIFY_SOURCE=2 -W -Wall -Wbad-function-cast -Wcast-align	\
           -Wconversion -Wdisabled-optimization -Wendif-labels	\
           -Wfloat-equal -Wformat=2 -Winline		\
           -Wmissing-declarations -Wmissing-prototypes -Wnested-externs		\
           -Wno-conversion -Wno-unused-parameter -Wpointer-arith -Wshadow	\
           -Wstrict-prototypes -Wswitch -Wundef -Wuninitialized			\
           -Wwrite-strings -g3 -pedantic

CFLAGS += -Wall $(WARNINGS)
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

%.c: %.h geekcode.h

clean:
	rm -f $(TARGET) $(LIBFILES)

geekcode: $(LIBFILES)
	${CC} ${LDFLAGS} -o ${TARGET} ${LIBFILES}

install:
	install -m 755 geekcode /usr/local/bin
