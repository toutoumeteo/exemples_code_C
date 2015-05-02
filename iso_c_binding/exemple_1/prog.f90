program main
  use iso_c_binding
  implicit none
  interface
     subroutine my_routine(p,r,c) bind(c,name='myC_func')
       import :: c_ptr
       import :: c_int
       type(c_ptr), value :: p
       integer(c_int), value :: r
       integer(c_int), value :: c
     end subroutine my_routine
  end interface
  real (c_double), allocatable, target :: xyz(:,:)
  real (c_double), target :: abc(7,3)
  type(c_ptr) :: cptr
  allocate(xyz(7,3))
  cptr = c_loc(xyz(1,1))
  write(*,'(a,z20)') '#fortran address:', c_loc(abc(1,1))
  xyz=-1.0
  call my_routine(cptr,7,3)
  xyz(1,1)=1.0
  xyz(2,1)=2.0
  xyz(3,1)=3.0
  call my_routine(cptr,7,3)
  deallocate(xyz)
  
  write(*,'(a,z20)') '#fortran address:', c_loc(abc(1,1))
  cptr = c_loc(abc(1,1))
  abc=-5.0
  call my_routine(cptr,7,3)
  abc(1,1)=11.0
  abc(2,1)=12.0
  abc(3,1)=13.0
  call my_routine(cptr,7,3)
  
end program main
