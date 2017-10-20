CC=gcc
CFLAGS=-Wall -I. -lpcap
SRC=krack.c
EDIR=./exploits/
CVESRC=$(EDIR)CVE-2017-13077.c $(EDIR)CVE-2017-13078.c $(EDIR)CVE-2017-13079.c $(EDIR)CVE-2017-13080.c $(EDIR)CVE-2017-13081.c $(EDIR)CVE-2017-13082.c

all: compile

compile:
	$(CC) $(CFLAGS) $(SRC) $(CVESRC) -o krack

clean:
	rm -f krack 
