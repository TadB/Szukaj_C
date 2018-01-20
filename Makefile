PROG = szukaj
CC=gcc
CFLAGS=-c -Wall -std=c11
OBJS= main.o power.o szukaj.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
main.o : main.c
	$(CC) $(CFLAGS) main.c
power.o : power.h power.c
	$(CC) $(CFLAGS) power.c
szukaj.o : szukaj.h szukaj.c
	$(CC) $(CFLAGS) szukaj.c
clean:
	rm -f $(PROG) $(OBJS)
