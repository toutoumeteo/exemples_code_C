program prog_f

  implicit none
  
  interface
   integer function my_func(F_i, F_f, F_io, F_fo) result(stat)
       implicit none
       integer :: F_i
       real :: F_f
       integer, optional :: F_io
       real, optional :: f_fo 
     end function my_func
  end interface

  integer :: ier

  print*,'====================='
  print*,'Passing all arguments'
  print*,'my_func(1,1.,2,2.)'
  ier = my_func(1,1.,2,2.)

  print*,'==========================='
  print*,'Passing first two arguments'
  print*,'my_func(1,1.)'
  ier = my_func(1,1.)

end program prog_f

integer function my_func(F_i, F_f, F_io, F_fo) result(stat)

  use iso_c_binding, only : c_int, c_float, c_ptr, c_loc, C_NULL_PTR

  implicit none

  interface
     subroutine c_optional(F_i, F_f, F_io, F_fo) bind(c)
       use iso_c_binding, only : c_int, c_float, c_ptr
       integer(c_int), value :: F_i
       real(c_float), value :: F_f
       type(c_ptr),value :: F_io
       type(c_ptr),value :: F_fo
     end subroutine c_optional
  end interface

  integer :: F_i
  real :: F_f
  integer, optional :: F_io
  real, optional :: f_fo 

  ! Local variables
  integer(c_int), target :: io_CI
  type(c_ptr) :: io_CP

  real(c_float), target :: fo_CF
  type(c_ptr) :: fo_CP

  print*,'F_i = ',F_i
  print*,'F_f = ',F_f
  
  if(present(F_io))then
     print*,'F_io = ',F_io
     io_CI=F_io
     io_CP = c_loc(io_CI)
  else
     io_CP = C_NULL_PTR
  endif

  if(present(F_fo))then
     print*,'F_fo = ',F_fo
     fo_CF = F_fo
     fo_CP = c_loc(fo_CF)
  else
     fo_CP = C_NULL_PTR
  endif

  call c_optional(F_i, F_f, io_CP, fo_CP)

  stat=0
  
end function my_func
