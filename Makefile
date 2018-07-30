#Ken Jinks
#Aug 2018
#Jinks Draw

CC = g++

CFLAGS = -c -Wall `pkg-config --cflags --libs gtk+-3.0`

all: jinksDraw

jinksDraw: main.o primitives.o
	$(CC) main.o primitives.o -o jinksDraw

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

primitives.o: primitives.cpp primitives.h
	$(CC) $(CFLAGS) primitives.cpp

prime_test: prime_test.o primitives.o
	$(CC) prime_test.o primitives.o -o prime_test

prime_test.o: prime_test.cpp
	$(CC) $(CFLAGS) prime_test.cpp

clean:
	rm -f *.o prime_test jinksDraw
