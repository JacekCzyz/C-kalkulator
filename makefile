CC = gcc
all: kalkulator.o pop_push_init.o
	$(CC) kalkulator.o pop_push_init.o -o kalkulator -lm
kalkulator.o: kalkulator.c header.h 
	$(CC) kalkulator.c -c -o kalkulator.o
pop_push_init.o: pop_push_init.c header.h 
	$(CC) pop_push_init.c -c -o pop_push_init.o