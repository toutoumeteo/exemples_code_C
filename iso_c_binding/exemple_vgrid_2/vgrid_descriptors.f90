module vGrid_Descriptors
  use iso_c_binding
  implicit none
  
  type vgrid_descriptor
     type(c_ptr) :: cptr
  end type vgrid_descriptor

  interface
     type(c_ptr) function vgd_new_c () bind(c,name='VGD_New')
       import :: c_ptr
     end function vgd_new_c
     subroutine vgd_print_c(vgd) bind(c,name='VGD_Print')
       import :: c_ptr
       type(c_ptr), value :: vgd
     end subroutine vgd_print_c
  end interface

  interface vgd_new
     module procedure new_gen
  end interface vgd_new

  interface vgd_print
     module procedure print_descript
  end interface vgd_print

contains

  integer function new_gen(self) result(istat)
    type(vgrid_descriptor) :: self
    istat =0;
    self%cptr = vgd_new_c()
    istat =1;
  end function new_gen

   integer function print_descript(self) result(istat)
    type(vgrid_descriptor) :: self
    istat =0;
    call vgd_print_c(self%cptr)
    istat =1;
  end function print_descript
 
  
end module vGrid_Descriptors

