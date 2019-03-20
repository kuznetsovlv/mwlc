#Makefile

mwlc: main.o mwlc_path.o mwlc_str.o
	gcc -o mwlc main.o mwlc_path.o mwlc_str.o
2absp: 2absp.o mwlc_path.o mwlc_str.o
	gcc -o 2absp 2absp.o mwlc_path.o mwlc_str.o
main.o: main.c
	gcc -c main.c
2absp.o: 2absp.c
	gcc -c 2absp.c
mwlc_path.o: mwlc_path.c
	gcc -c mwlc_path.c
mwlc_str.o: mwlc_str.c
	gcc -c mwlc_str.c
clean:
	rm -f mwlc 2absp *.o *.gz
