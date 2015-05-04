program caracter

  use iso_c_binding, only : c_null_char, c_ptr

  implicit none

  character(len=5) :: nomvar

  nomvar='ABCD'
  print*,'namvar',nomvar
  nomvar=nomvar//c_null_char
  print*,'namvar',nomvar    

end program caracter
