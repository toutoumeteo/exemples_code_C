program prog_f

  use iso_c_binding, only : c_ptr, c_loc

  implicit none

  interface
     subroutine c_sub1(my_intp, my_intv) bind(c)
       use iso_c_binding, only : c_int
       ! The first  argument is passed by reference (must be a int pointer in the c function)
       ! The second argument is passed by value     (must be a int         in the c function)
       integer(c_int)        :: my_intp
       integer(c_int), value :: my_intv
     end subroutine c_sub1

     subroutine c_sub2(my_intpp, my_intpv) bind(c)
       use iso_c_binding, only : c_int, c_ptr
       ! The first  argument is passed by reference (must be a pointer to a pointer in the c function)       
       ! The second argument is passed by value     (must be a pointer              in the c function)
       type(c_ptr)        :: my_intpp
       type(c_ptr), value :: my_intpv
     end subroutine c_sub2

  end interface

  integer, target :: var
  type (c_ptr), target :: varp
  type (c_ptr) :: varpp

  var   = 2
  varp  = c_loc(var)  
  varpp = c_loc(varp)

  write(6,'("In main : addresse of var from  c_loc(var) is : varp = ",z12)')varp
  
  ! The first argument is passed by reference, the second by value (see interface above)
  call c_sub1(var,var)

  write(6,'("In main : addresse of varp from  c_loc(varp) is : varpp = ",z12)')varpp

  ! The first argument is passed by reference, the second by value (see interface above)
  call c_sub2(varp,varp)

end program prog_f
