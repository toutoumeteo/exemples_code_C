module vGrid_Descriptors

  use iso_c_binding, only : c_ptr

  implicit none
  
  type vgrid_descriptor
     ! The only member of this type is a C pointer
     type(c_ptr) :: cptr
  end type vgrid_descriptor

  interface

     type(c_ptr) function vgd_new_c () bind(c,name='VGD_New')
       use iso_c_binding, only : c_ptr
     end function vgd_new_c

     subroutine vgd_print_c(vgd) bind(c,name='VGD_Print')
       use iso_c_binding, only : c_ptr
       type(c_ptr), value :: vgd
     end subroutine vgd_print_c

     subroutine vgd_free_c(vgd) bind(c,name='VGD_Free')
        use iso_c_binding, only : c_ptr
       type(c_ptr),value :: vgd
     end subroutine vgd_free_c

     subroutine vgd_free_c2(vgd) bind(c,name='VGD_Free2')
        use iso_c_binding, only : c_ptr
       type(c_ptr) :: vgd
     end subroutine vgd_free_c2

  end interface

  interface vgd_new
     module procedure new_gen
  end interface vgd_new

  interface vgd_print
     module procedure print_descript
  end interface vgd_print

  interface vgd_free
     module procedure garbage_collection
  end interface vgd_free

  interface vgd_free2
     module procedure garbage_collection2
  end interface vgd_free2

contains

  integer function new_gen(self) result(istat)
    ! Wrapper function to C vgd_new_c
    type(vgrid_descriptor) :: self
    istat =0;
    self%cptr = vgd_new_c()
    istat =1;
  end function new_gen

  integer function print_descript(self) result(istat)
     ! Wrapper function to C vgd_print_c
     type(vgrid_descriptor) :: self
     istat =0;
     call vgd_print_c(self%cptr)
     istat =1;
  end function print_descript
  
  integer function garbage_collection(self) result(istat)
     ! Wrapper function to C vgd_free_c
     type(vgrid_descriptor) :: self
     istat =0;
     call vgd_free_c(self%cptr)
     istat =1;
  end function garbage_collection

  integer function garbage_collection2(self) result(istat)
     ! Wrapper function to C vgd_free_c
     type(vgrid_descriptor) :: self
     istat =0;
     call vgd_free_c2(self%cptr)
     istat =1;
  end function garbage_collection2

end module vGrid_Descriptors

