#include <stdio.h>

void my_func(int **pptr);

int main ()
{
   int  var;
   int  *ptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   printf("Value of var = %d\n", var );
   printf("Value available at   *ptr = %d\n",   *ptr);
   printf("Value available at    ptr = %p\n",    ptr);

   my_func(&ptr);

   return 0;
}

void my_func(int **pptr)
{
  // This function receives a pointer to a pointer.
   printf("In my_func: Value available at **pptr = %d\n", **pptr);
   printf("In my_func: Value available at  *pptr = %p\n",  *pptr);
   printf("In my_func: Value available at   pptr = %p\n",   pptr);
}
