CC=gcc
# ri_gk_4way_hs.c  ri_gk.c  ri_igk_4way_hs.c  ri_igk.c  ri_pk_4way_hs.c  ri_pk_accept_rftrr.c
CFLAGS=-Wall -I.
SRC='krack.c'
EDIR='exploits/'
CVESRC="$(EDIR)CVE-2017-13077.c $(EDIR)CVE-2017-13078.c $(EDIR)CVE-2017-13079.c $(EDIR)CVE-2017-13080.c $(EDIR)CVE-2017-13081.c $(EDIR)CVE-2017-13082.c"

all: mkbin exploits

exploits:
	$(CC) $(CFLAGS) $(SRCFILES) -o ./bin/kcrack

mkbin:
	if [ ! -d bin ]; then mkdir bin; fi

clean:
	rm -rf *.o
	[[ -d bin ]] && rm -rf bin

.SILENT: mkbin clean
