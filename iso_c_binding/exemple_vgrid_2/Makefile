CC = gcc
FC = gfortran

C_OBJECTS = vgrid.o
F_OBJECTS = vgrid_descriptors.o use_vgrid_f.o

%.o: %.c
	$(CC) -c $<

%.o: %.f90
	$(FC) -c $<

use_vgrid_c: use_vgrid_c.c $(C_OBJECTS) $(F_OBJECTS)
	$(CC) use_vgrid_c.c -o use_vgrid_c $(C_OBJECTS)

use_vgrid_f: $(C_OBJECTS) $(F_OBJECTS)
	$(FC) $(C_OBJECTS) $(F_OBJECTS) -o use_vgrid_f

clean: 
	rm -f *.o ;\

distclean: clean
	rm -f use_vgrid_c use_vgrid_f ;\
