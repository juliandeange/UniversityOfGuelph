
OPTIONS = -pedantic -Wall -Werror

a.out: myProgram.o StudentImplementation.o ListImplementation.o
	gcc $(OPTIONS) $(FLAG) myProgram.o StudentImplementation.o ListImplementation.o

myProgram.o: myProgram.c StudentInterface.h StudentType.h ListInterface.h ListType.h
	gcc $(OPTIONS) -c $(FLAG) myProgram.c

StudentImplementation.o: StudentImplementation.c StudentInterface.h StudentType.h
	gcc $(OPTIONS) -c $(FLAG) StudentImplementation.c

ListImplementation.o: ListImplementation.c ListInterface.h ListType.h StudentInterface.h StudentType.h
	gcc $(OPTIONS) -c $(FLAG) ListImplementation.c

clean:
	rm *.o a.out

















