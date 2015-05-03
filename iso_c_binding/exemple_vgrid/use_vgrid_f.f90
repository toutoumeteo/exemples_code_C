program main
  use iso_c_binding

  implicit none

  interface
     type(c_ptr) function vgd_new () bind(c,name='VGD_New')
       import :: c_ptr
     end function vgd_new
     subroutine vgd_print(vgd) bind(c,name='VGD_Print')
       import :: c_ptr
       type(c_ptr), value :: vgd
     end subroutine vgd_print
  end interface

  type(c_ptr) :: vgd

  vgd = vgd_new()
  call vgd_print(vgd)

end program main
