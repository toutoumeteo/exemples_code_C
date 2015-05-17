program prog_f

   use iso_c_binding, only : c_ptr, c_loc

   implicit none

   interface

      subroutine c_vec_mlt_by_2(vecp,size) bind(c)
         use iso_c_binding, only : c_ptr, c_int
         type(c_ptr), value :: vecp
         integer(c_int), value :: size
       end subroutine c_vec_mlt_by_2

   end interface

   integer :: i,j,k,ind
   integer, dimension(3) :: lbound_3d
   real, pointer, dimension(:,:,:) :: vec
   real, target, dimension(3) :: vec2
   type(c_ptr) :: vec_CP

   allocate(vec(-1:1,10:11,-12:-11))
   
   ind=1
   do k=-12,-11
      do j=10,11
         do i=-1,1
            vec(i,j,k)=ind
            ind=ind+1
         end do
      end do
   enddo
   vec2=(/1., 2., 3./)

   lbound_3d = lbound(vec)
   vec_CP = c_loc( vec( lbound_3d(1),lbound_3d(2),lbound_3d(3) ) )
   write(6,'("In Fortran vec_CP",z16)')vec_CP
   print*,'In Fortran, value are',vec
   call c_vec_mlt_by_2(vec_CP,size(vec))

   vec_CP = c_loc(vec2)
   write(6,'("In Fortran vec_CP",z16)')vec_CP
   call c_vec_mlt_by_2(vec_CP,size(vec2))

   print*,'`Back in Fortran, value are',vec

end program prog_f
