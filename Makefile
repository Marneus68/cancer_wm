PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include cancer_wm.c -L$(PREFIX)/lib -lX11 -o cancer_wm 

clean:
	rm -f cancer_wm

install:
	install -Dm755 cancer_wm-session /usr/bin/cancer_wm-session
	install -Dm755 cancer_wm /usr/bin/cancer_wm
	cp cancer_wm-session.desktop /usr/share/xsessions/cancer_wm-session.desktop

uninstall:
	rm -f /usr/bin/cancer_wm-session
	rm -f /usr/bin/cancer_wm
	rm -f /usr/share/xsessions/cancer_wm-session.desktop

