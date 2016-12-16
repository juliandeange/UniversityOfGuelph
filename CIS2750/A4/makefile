listio: listio.c listio.h db.c
	gcc -c listio.c -o listio.o -g
	ar cr liblistio.a listio.o
	gcc main.c listio.o -L. -llistio -lmysqlclient -L/usr/local/mysql/lib -g -o a4 
	gcc db.c -o db -lmysqlclient -L/usr/local/mysql/lib -g

clean:
	rm files/test.txt.html files/test.html toPython toC
	