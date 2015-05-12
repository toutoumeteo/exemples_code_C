CC = gcc
FC = gfortran

C_OBJECTS = vgrid.o
F_OBJECTS = vgrid_descriptors.o use_vgrid_f.o

%.o: %.c
	$(CC) -c $< -g

%.o: %.f90
	$(FC) -c $< -g -C

defaul: use_vgrid_f

use_vgrid_c: use_vgrid_c.c $(C_OBJECTS) $(F_OBJECTS)
	$(CC) $@.c -o $@ $(C_OBJECTS)

use_vgrid_f: $(C_OBJECTS) $(F_OBJECTS)
	$(FC) $(C_OBJECTS) $(F_OBJECTS) -o $@

clean: 
	rm -f *.o *.mod ;\

distclean: clean
	rm -f use_vgrid_c use_vgrid_f ;\

bigclean: distclean
	rm -f *~ ;\
