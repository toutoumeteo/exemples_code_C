!https://software.intel.com/en-us/node/510852

program demo_c_f_pointer
  use, intrinsic :: iso_c_binding
  implicit none
  
  interface
     function make_array(n_elements) bind(C)
       import ! Make iso_c_binding visible here
       type(C_PTR) :: make_array
       integer(C_INT), value, intent(IN) :: n_elements
     end function make_array
  end interface
  
  type(C_PTR) :: cptr_to_array
  integer(C_INT), pointer :: array(:) => NULL()
  integer, parameter :: n_elements = 3 ! Number of elements
  
  ! Call C function to create and populate an array
  cptr_to_array = make_array(n_elements)
  ! Convert to Fortran pointer to array of n_elements elements
  call C_F_POINTER (cptr_to_array, array, [n_elements])
  ! Print value
  print *, array

  print*,"size(array)=",size(array)
  print*,"associated(array)=",associated(array)
  
end program demo_c_f_pointer
