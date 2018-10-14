CC=gcc
CFLAGS=-lWarn -pedantic

output: irtester.o libmyifttt.a
        $(CC) irtester.o -L. -lwiringPi -lmyifttt -lcurl -o irtester


tester: tester.o libmyifttt.a
        $(CC) tester.o -L. -lmyifttt -lcurl -o tester

libmyifttt.a:   ifttt.o
        ar -rcs libmyifttt.a ifttt.o

ifttt.o:        ifttt.c ifttt.h
        $(CC) $(CFLAGS) -c -ansi $<

tester.o:       tester.c ifttt.h
        $(CC) $(CFLAGS) -c -ansi $<
	
clean:   rm tester *.o

all:  tester output





