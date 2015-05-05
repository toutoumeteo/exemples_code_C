CC = gcc
FC = gfortran

C_OBJECTS = c_print_string.o
F_OBJECTS = prog_f.o

%.o: %.c
	$(CC) -c $<

%.o: %.f90
	$(FC) -c $<

defaul: prog_f

prog_f: $(C_OBJECTS) $(F_OBJECTS)
	$(FC) $(C_OBJECTS) $(F_OBJECTS) -o $@

clean: 
	rm -f *.o *.mod ;\

distclean: clean
	rm -f prog_f ;\

bigclean: distclean
	rm -f *~ ;\
