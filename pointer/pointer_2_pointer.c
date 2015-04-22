// Inspire de :
//http://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm

#include <stdio.h>

int main ()
{
   int  var;
   int  *ptr = NULL;
   int  **pptr = NULL;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   printf("Value of var = %d\n", var );
   printf("Value available at   *ptr = %d\n",   *ptr);
   printf("Value available at    ptr = %p\n",    ptr);
   printf("Value available at **pptr = %d\n", **pptr);
   printf("Value available at  *pptr = %p\n",  *pptr);
   printf("Value available at   pptr = %p\n",   pptr);

   return 0;
}

