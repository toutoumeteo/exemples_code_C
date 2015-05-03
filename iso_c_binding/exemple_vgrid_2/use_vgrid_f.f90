program main
  use iso_c_binding
  use vGrid_Descriptors

  implicit none

  integer :: ier
  type(vgrid_descriptor) :: vgd

  ier = vgd_new(vgd)
  ier = vgd_print(vgd)

end program main
