// Inspirer de :
// http://www.tutorialspoint.com/cprogramming/c_pointers.htm

#include <stdio.h>

void my_check_pointer(int *ip);

int main ()
{
   int  var = 20;    /* actual variable declaration */
   int  *ip = NULL;  /* pointer variable declaration */
   
   printf("Value of ip variable before assignation: %p\n", ip );

   my_check_pointer(ip);

   ip = &var;  /* store address of var in pointer variable*/

   my_check_pointer(ip);

   printf("Address of var variable: %p\n", &var  );

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %p\n", ip );

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );

   return 0;
}


void my_check_pointer(int *ip)
{
  printf("  Function my_check_pointer begins\n");
  if(!ip)
    printf("    Pointer is NULL\n");
  if(ip){
    printf("    Pointer address is %p\n",&ip);
    printf("    Pointer points to %p\n",ip);
    printf("    Value where pointer points %d\n",*ip);
  }
  printf("  Function my_check_pointer ends\n");
}
