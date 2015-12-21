
OPTIONS = -pedantic -Wall -Werror

a.out: myProgram.o StackImplementation.o
	gcc $(OPTIONS) $(FLAG) myProgram.o StackImplementation.o

myProgram.o: myProgram.c StackInterface.h StackType.h
	gcc $(OPTIONS) -c $(FLAG) myProgram.c

StackImplementation.o: StackImplementation.c StackInterface.h StackType.h
	gcc $(OPTIONS) -c $(FLAG) StackImplementation.c

clean:
	rm *.o a.out


















