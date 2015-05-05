program caracter

  use iso_c_binding, only : c_char, c_null_char, c_ptr

  implicit none

  interface
     subroutine c_print_string(string) bind(c,name='c_print_string')
       use iso_c_binding, only : c_char
       character(kind=c_char) :: string(*)
     end subroutine c_print_string
  end interface

  character(kind=c_char,len=5) :: nomvar
  character(kind=c_char,len=5) :: nomvar2
  character(kind=c_char,len=5) :: nomvar3

  nomvar='ABCD'
  nomvar2='EFGH'
  nomvar3='IJKL'
  print*,'nomvar=',nomvar
  print*,'c_null_char=(',c_null_char,')'
  nomvar=nomvar//c_null_char
  print*,'nomvar=',nomvar    

  call c_print_string(c_char_"ANDRE"//c_null_char)
  call c_print_string(nomvar)
  call c_print_string(nomvar2//c_null_char)
  call c_print_string(nomvar3) ! This is an error, no null char at the end!
  call c_print_string(nomvar3//c_null_char)

end program caracter
