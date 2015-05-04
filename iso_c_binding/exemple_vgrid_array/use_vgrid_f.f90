program main
  use iso_c_binding
  use vGrid_Descriptors

  implicit none

  integer :: ier, load_vector_1d_8, load_vector_2d_8,j,ni,nj
  type(vgrid_descriptor) :: vgd

  real*8 :: ff_8(3),ff2_8(2,3)

  ier = vgd_new(vgd)
  ier = vgd_print(vgd)
  
  ier = load_vector_1d_8(ff_8,size(ff_8))
  print*,ff_8

  ni=size(ff2_8,1)
  nj=size(ff2_8,2)
  ier = load_vector_2d_8(ff2_8,ni,nj)
  
  do j=nj,1,-1
     print*,ff2_8(1:ni,j)
  end do

end program main
