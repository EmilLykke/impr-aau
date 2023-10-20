CC = gcc

prog: ppm.o pixel.o
	$(CC) -lm prog.c pixel.o ppm.o -o prog

ppm.o: ppm.h ppm.c
	$(CC) -c ppm.c

pixel.o: pixel.c pixel.c
	$(CC) -c pixel.c