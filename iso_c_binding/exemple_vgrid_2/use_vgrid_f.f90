program main
  use iso_c_binding
  use vGrid_Descriptors

  implicit none

  integer :: ier
  type(vgrid_descriptor) :: vgd

  ier = vgd_new(vgd)
  write(6,'("In Fortran : vgd%cprt = ",z16)')vgd%cptr
  ier = vgd_print(vgd)
  ier = vgd_free(vgd)
  ier = vgd_print(vgd)

end program main
