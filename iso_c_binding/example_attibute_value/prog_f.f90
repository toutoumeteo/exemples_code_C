program prog_f

  use iso_c_binding, only : c_ptr, c_loc

  implicit none

  interface
     subroutine c_sub1(my_intp, my_intv) bind(c)
       use iso_c_binding, only : c_int
       integer(c_int)        :: my_intp
       integer(c_int), value :: my_intv
     end subroutine c_sub1

     subroutine c_sub2(my_intpp, my_intpv) bind(c)
       use iso_c_binding, only : c_int, c_ptr
       type(c_ptr)        :: my_intpp
       type(c_ptr), value :: my_intpv
     end subroutine c_sub2

  end interface

  integer, target :: var
  type (c_ptr) :: varp

  var = 2
  varp = c_loc(var)
  
  call c_sub1(var,var)

  call c_sub2(varp,varp)

end program prog_f
