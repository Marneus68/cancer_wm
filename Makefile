PREFIX?=/usr/include/X11
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -lX11 -o cancer_wm cancer_wm.c

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

