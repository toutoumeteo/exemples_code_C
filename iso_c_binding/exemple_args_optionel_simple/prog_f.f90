program prog_f

  ! Andre Plante mai 2015
  !
  ! Use my_func which has one mandatory argument and one optional argument.
  ! my_func calls a c function simulating optional arguments with NULL pointer (see details below).

  implicit none
  
  interface
   integer function my_func(man, opt) result(stat)
       implicit none
       integer :: man
       integer, optional :: opt
     end function my_func
  end interface

  integer :: ier

  print*,'==================================='
  print*,'Passing only the mandatory argument'
  print*,'my_func(1)'
  ier = my_func(1)

  print*,'====================='
  print*,'Passing all arguments'
  print*,'my_func(1,2)'
  ier = my_func(1,2)

end program prog_f

integer function my_func(man, opt) result(stat)

  ! Andre Plante mai 2015
  !
  ! This function calls function c_optional which simulates optional argument via the usage of C_NULL_PTR
  !
  ! If the optional argument is present (integer opt)
  !
  !    The value of opt is copied in opt_CI which is of type c_int (_CI for C int).
  !    Variable opt_CI must be a target since we need to get its C location
  !    with iso_c_binding c_loc(opt_CI) function.
  !
  !    integer(c_int), target :: opt_CI
  !
  !    The C location of opt_CI is written in opt_CP which is a c_ptr variable (_CP for C Pointer).
  !
  !    type(c_ptr) :: opt_CP
  !
  !    This pointer will be passed to the C function by value (pointer value).
  !    This is why the 'value' attribute is added to its declaration in the
  !    c_optional interface.
  !
  !    type(c_ptr),value :: opt
  !    
  !
  ! If the optional argument is not present (integer opt)
  !
  !    The pointer opt_CP is set to C_NULL_PTR
  !
  ! The C function c_optional check if the pointer is NULL to find out if the option must be
  ! applied or not.
  !
  ! Question : It look like the use of the intermediate variable opt_CI is not
  !            necessary if we add the attribute 'target' to opt.
  !            (see the "Can we do this?" comments below)
  !            However, the documentation of c_loc() 
  
  use iso_c_binding, only : c_int, c_float, c_ptr, c_loc, C_NULL_PTR, c_associated

  implicit none

  interface
     subroutine c_optional(man, opt) bind(c)
       use iso_c_binding, only : c_int, c_float, c_ptr
       integer(c_int), value :: man
       type(c_ptr),value :: opt
     end subroutine c_optional
  end interface

  integer :: man
  integer, optional :: opt
  ! Can we do this instead?
  ! Can an optional argument be a target?
  ! integer, target, optional :: opt

  ! Local variables, this may not be need if we can do the above
  integer(c_int), target :: opt_CI
  type(c_ptr) :: opt_CP

  print*,'man = ', man
  
  if(present(opt))then
     print*,'opt = ',opt
     opt_CI=opt
     opt_CP = c_loc(opt_CI)
     ! Can we do this and avoid intermidiate variable opt_CI
     ! opt_CP = c_loc(opt)
  else
     opt_CP = C_NULL_PTR
  endif

  call c_optional(man, opt_CP)

  stat=0
  
end function my_func
