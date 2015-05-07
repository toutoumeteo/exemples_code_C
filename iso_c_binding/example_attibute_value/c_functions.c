#include <stdio.h>

void c_sub1(int *varp, int varv)
{
  printf("\n");
  printf("   In c_sub1   pointer varp points to address  :  varp =  %p\n",  varp);
  printf("   In c_sub1   value at that address           : *varp =  %d\n", *varp);
  printf("   In c_sub1   address of varv is local to s/r : &varv =  %p\n", &varv);
  printf("   In c_sub1   Value at this address           :  varv =  %d\n",  varv);
  printf("\n");
}

void c_sub2(int **varpp, int *varpv)
{
  printf("\n");
  printf("   In c_sub2   pointer to pointer varpp points to address     :   varpp =  %p\n",   varpp);
  printf("   In c_sub2   address contained at that location is          :  *varpp =  %p\n",  *varpp);
  printf("   In c_sub2   value at that address is the final distination : **varpp =  %d\n", **varpp);
  printf("\n");
  printf("   In c_sub2   pointer varpv points to address                :   varpv =  %p\n",   varpv);
  printf("   In c_sub2   value at that address is the final distination :  *varpv =  %d\n",  *varpv);
  printf("\n");
}

