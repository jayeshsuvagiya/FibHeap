CC=g++

CFLAGS=-c -Wall

all:keywordcounter

keywordcounter: main.o fibheap.o
	$(CC) main.o fibheap.o -o keywordcounter

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

fibheap.o: fibheap.cpp
	$(CC) $(CFLAGS) fibheap.cpp

clean:
	rm -rf *o keywordcounter


