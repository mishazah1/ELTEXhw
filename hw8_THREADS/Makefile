CC=gcc

CFLAGS=-lpthread -c -Wall 

bin=threads

all: $(bin)

$(bin): main.o 
	$(CC) main.o -o $(bin) -lpthread

main.o:main.c
	$(CC) $(CFLAGS) main.c

start:
	./$(bin)

clean:
	rm -rf *.o $(bin)