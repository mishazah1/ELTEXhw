CC=gcc

CFLAGS=-c -Wall

all: phones

phones: main.o phones.o 
	$(CC) main.o phones.o -o phones

main.o:main.c
	$(CC) $(CFLAGS) main.c

phones.o:
	$(CC) $(CFLAGS) phones.c

clean:
	rm -rf *.o phones
