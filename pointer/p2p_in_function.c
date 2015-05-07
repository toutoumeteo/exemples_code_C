#include <stdio.h>

void my_func(int **pptr);

int val = 6000;

int main ()
{
   int  var;
   int  *ptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   printf("\n");
   printf("Pointer ptr points to var      :   var = %d\n",  var);
   printf("Value pointed to by ptr        :  *ptr = %d\n", *ptr);
   printf("Address where ptr points to    :   ptr = %p\n",  ptr);
   printf("Address of var                 :  &var = %p\n", &var);
   printf("Address of pointer             :  &ptr = %p\n", &ptr);
   
   printf("Passing address of ptr to function my_func\n\n");
   my_func(&ptr);
   printf("\n");
   printf("Back in main, value pointed to by ptr is now  :  *ptr = %d\n", *ptr);
   printf("\n");
   

   return 0;
}

void my_func(int **pptr)
{
  // This function receives a pointer to a pointer.
  printf("   In my_func: receiving address of ptr in pointer to pointer pptr\n");
  printf("   In my_func: Address in pptr is the one of ptr in main         :   pptr = %p\n",   pptr);
  printf("   In my_func: Value pointed by pptr is address of var           :  *pptr = %p\n",  *pptr);
  printf("   In my_func:                                                     **pptr = %d\n", **pptr);
  printf("\n");
  printf("   In my_func: We now change the address in *ptr to the one of variable val \n");
  printf("                  with line of code *pptr = &val;\n");
  *pptr = &val;
  printf("   In my_func: Address of val                                    :   &val = %p\n",   &val);
  printf("   In my_func: Value pointed by pptr is address of val           :  *pptr = %p\n",  *pptr);
  printf("   In my_func: Address in pptr is still the one of ptr from main :   pptr = %p\n",   pptr);
  printf("   In my_func: The value of val is                               :    val = %d\n",    val);
  printf("   In my_func:                                                     **pptr = %d\n", **pptr);
}
