program prog_f

  use iso_c_binding, only : c_int

  implicit none

  interface

     subroutine c_sub(my_int, my_intp)
       use iso_c_binding, only : c_int
       integer(c_int) :: my_int
       integer(c_int), value :: my_intp)       
     end subroutine c_sub

  end interface

  integer :: var

  var = 2
  
  call c_sub(var,var)

end program prog_f
