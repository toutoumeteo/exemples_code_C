program prog_f

  use iso_c_binding, only : c_ptr, c_loc

  implicit none

  interface

     subroutine c_sub1(varp) bind(c)
        use iso_c_binding, only : c_int
        ! Argument is passed by reference (must be a int pointer in the c function)
        integer(c_int)        :: varp
     end subroutine c_sub1
     
     subroutine c_sub2(varv) bind(c)
        use iso_c_binding, only : c_int
        ! Argument is passed by value     (must be a int         in the c function)
        integer(c_int), value :: varv
     end subroutine c_sub2

     subroutine c_sub3(varpp) bind(c)
       use iso_c_binding, only : c_ptr
       ! Argument is passed by reference (must be a pointer to a pointer in the c function)       
       type(c_ptr)        :: varpp
     end subroutine c_sub3

     subroutine c_sub4(varpv) bind(c)
       use iso_c_binding, only : c_ptr
       ! Argument is passed by value     (must be a pointer              in the c function)
       type(c_ptr), value :: varpv
     end subroutine c_sub4

  end interface

  integer, target :: var         ! Must be a target because it will be pinted to
  type (c_ptr), target :: varp   ! Must be a target because it will be pinted to
  type (c_ptr) :: varpp

  var   = 2
  varp  = c_loc(var)
  varpp = c_loc(varp)
  
  print*
  print*,"========================================================================================="
  print*,"In Fortran"
  write(6,'("   Addresse of var  from iso_c_binding c_loc(var)  is   :    varp =   ",z12," = a1")')varp
  write(6,'("   Addresse of varp from iso_c_binding c_loc(varp) is   :   varpp =   ",z12," = a2")')varpp
  
  ! Reference of var passed to function
  call c_sub1(var)

  ! Value of var passed to function
  call c_sub2(var)

  ! Reference of pointer varp passed to function
  call c_sub3(varp)

  ! Value of pointer varp passed to function
  call c_sub4(varp)

  print*
  print*,"========================================================================================="

end program prog_f
