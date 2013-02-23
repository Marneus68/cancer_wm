TARGET  := $(shell basename $$PWD)
WARN    := -pedantic -Wall
OFLAGS  := -Os
PREFIX?=/usr/X11R6
CDLAGS  := -I$(PREFIX)/include ${OFLAGS} ${WARN}
LDFLAGS := -L$(PREFIX)/lib -lX11
CC      := gcc

C_SRCS      = $(wildcard *.c)
OBJ_FILES   = $(C_SRCS:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(LDFLAGS)

all: ${TARGET}

clean:
	rm -rf *.o

mrproper: clean
	rm ${TARGET}

install:
	install -Dm755 cancer_wm-session /usr/bin/cancer_wm-session
	install -Dm755 cancer_wm /usr/bin/cancer_wm
	cp cancer_wm-session.desktop /usr/share/xsessions/cancer_wm-session.desktop

uninstall:
	rm -f /usr/bin/cancer_wm-session
	rm -f /usr/bin/cancer_wm
	rm -f /usr/share/xsessions/cancer_wm-session.desktop

