program prog_f

  ! Andre Plante mai 2015
  !
  ! Use my_func which has optional argument
  ! my_func calls a c function simulating optional arguments with NULL pointer (see details below).

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

  print*,'===================================='
  print*,'Passing first two arguments F_fo'
  print*,'my_func(1,1.)'
  ier = my_func(1,1.,F_fo=2.)

  print*,'===================================='
  print*,'Passing first two arguments F_io'
  print*,'my_func(1,1.)'
  ier = my_func(1,1.,F_io=1)

end program prog_f

integer function my_func(F_i, F_f, F_io, F_fo) result(stat)

  ! Andre Plante mai 2015
  !
  ! This function calls function c_optional which simulates option arguments via the usage of C_NULL_PTR
  !
  ! If an optional argument is present, e.g. integer F_io (io for interger optional)
  !
  !    The value of F_io is copied in io_CI which is of type c_int (_CI for C).
  !    Variable io_CI must be a target since we need to get its C location
  !    with iso_c_binding c_loc function.
  !
  !    integer(c_int), target :: io_CI
  !
  !    The C location of io_CI is written in io_CP which is a c_ptr variable.
  !
  !    type(c_ptr) :: io_CP
  !
  !    This pointer will be passed to the C function by value (pointer value).
  !    This is why the attribute value is added to its declaration in the
  !    c function interface.
  !
  !    type(c_ptr),value :: F_io
  !    
  !
  ! If an optional argument not present, e.g. integer F_io
  !
  !    The pointer io_CP is set to C_NULL_PTR
  !
  ! The C function check if the pointer is NULL to find out if the option must be
  ! done or not.

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
