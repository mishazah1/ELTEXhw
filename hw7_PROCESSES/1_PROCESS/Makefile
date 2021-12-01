CC=gcc

CFLAGS=-c -Wall

bin=process

all: $(bin)

$(bin): main.o 
	$(CC) main.o -o $(bin)

main.o:main.c
	$(CC) $(CFLAGS) main.c

start:
	./$(bin)

clean:
	rm -rf *.o $(bin)