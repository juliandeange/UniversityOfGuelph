listio: listio.c listio.h
	gcc -c listio.c -o listio.o -g
	ar cr liblistio.a listio.o
	gcc main.c listio.o -L. -llistio -g -o a2

clean:
	rm files/test.txt.html files/test.html toPython toC
