#Makefile

mwlc: main.o
	gcc -o mwlc main.o
main.o: main.c
	gcc -c main.c
clean:
	rm -f mwlc *.o
