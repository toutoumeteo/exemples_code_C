OBJECTS = prog.o myC_func.o

all: $(OBJECTS)
	gfortran $(OBJECTS) -o main.exe

prog.o:	prog.f90
	gfortran -c prog.f90

myC_func.o: myC_func.c
	gcc -c myC_func.c

clean:
	rm -f *.o \;

distclean: clean
	rm -f  main.exe ;\
