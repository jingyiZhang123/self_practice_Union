
CC=c99
CFLAGS=-c -Wall

all: clean main
	./main

main: main.o helper.o union1.o union2.o union3.o union4.o union5.o
	$(CC) -o main main.o helper.o union1.o union2.o union3.o union4.o union5.o

main.o:
	$(CC) $(CFLAGS) main.c

union1.o:
	$(CC) $(CFLAGS) union1.c

union2.o:
	$(CC) $(CFLAGS) union2.c

union3.o:
	$(CC) $(CFLAGS) union3.c

union4.o:
	$(CC) $(CFLAGS) union4.c

union5.o:
	$(CC) $(CFLAGS) union5.c


helper.o:
	$(CC) $(CFLAGS) helper.c

clean:
	rm -rf *.o main
