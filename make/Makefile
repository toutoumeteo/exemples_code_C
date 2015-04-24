CC=gcc
CFLAGS=-I.

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

OBJECT = func1.o func2.o

default : main

main: $(OBJECT) main.c
	gcc main.c $(OBJECT) -I.

clean:
	rm -f *.o \;

bigclean: clean
	rm -f *~ \;
