program prog_f

  use iso_c_binding, only : c_ptr, c_loc, C_NULL_PTR

  implicit none

  interface

     subroutine C_Person_create(cptr) bind(c)
       use iso_c_binding, only : c_ptr
       type(c_ptr), value :: cptr
     end subroutine C_Person_create

  end interface

  integer :: ier
  type(c_ptr),target :: cptr

  cptr = C_NULL_PTR

  write(6,'("In Fortran:        cptr = ",z16)')      cptr
  write(6,'("In Fortran: c_loc(cptr) = ",z16)')c_loc(cptr)

  call C_Person_create(cptr)
  

end program prog_f
