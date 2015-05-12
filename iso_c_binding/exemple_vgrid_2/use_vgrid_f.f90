program main
  use iso_c_binding, only : C_NULL_PTR
  use vGrid_Descriptors

  implicit none

  integer :: ier
  type(vgrid_descriptor) :: vgd

  write(6,'("In Fortran BEFORE vgd_new:  vgd%cprt = ",z16)')vgd%cptr
  ier = vgd_new(vgd)
  write(6,'("In Fortran AFTER  vgd_new:  vgd%cprt = ",z16)')vgd%cptr
  ier = vgd_print(vgd)
  !ier = vgd_free(vgd)
  !write(6,'("In Fortran AFTER  vgd_free: vgd%cprt = ",z16)')vgd%cptr
  ier = vgd_free2(vgd)
  write(6,'("In Fortran AFTER  vgd_free2: vgd%cprt = ",z16)')vgd%cptr

end program main
