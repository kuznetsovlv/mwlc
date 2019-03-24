#Makefile
install_2absp: 2absp 2absp.1.gz
	cp 2absp.1.gz /usr/share/man/man1/
	mkdir -p /opt/mwlc/2absp
	cp 2absp /opt/mwlc/2absp
	ln -sf /opt/mwlc/2absp/2absp /usr/bin/2absp
mwlc: main.o mwlc_path.o mwlc_str.o mwlc_options.o
	gcc -o mwlc main.o mwlc_path.o mwlc_str.o mwlc_options.o
2absp.1.gz: 2absp.1
	gzip -k 2absp.1
2absp: 2absp.o mwlc_path.o mwlc_str.o mwlc_options.o
	gcc -o 2absp 2absp.o mwlc_path.o mwlc_str.o mwlc_options.o
main.o: main.c
	gcc -c main.c
2absp.o: 2absp.c
	gcc -c 2absp.c
mwlc_path.o: mwlc_path.c
	gcc -c mwlc_path.c
mwlc_str.o: mwlc_str.c
	gcc -c mwlc_str.c
mwlc_options.o: mwlc_options.c
	gcc -c mwlc_options.c
clean:
	rm -f mwlc 2absp *.o *.gz
