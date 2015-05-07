#include <stdio.h>

void c_sub1(int *varp)
{
  printf("\n");
  printf("   c_sub1, reference of scallar passed to function\n");
  printf("      Pointer varp points to address                    :    varp = %p = a1\n",    varp);
  printf("      Value at that address                             :   *varp = %d\n"     ,   *varp);
  printf("      Pointer address (only used here)                  :   &varp = %p = a4\n",   &varp);
}

void c_sub2(int varv)
{
  printf("\n");
  printf("   c_sub2, value of scallar passed to function\n");
  printf("      Value of varv                                     :    varv = %d\n"     ,    varv);
  printf("      Variable varv address (only used here)            :   &varv = %p = a5\n",   &varv);
}

void c_sub3(int **varpp)
{
  printf("\n");
  printf("   c_sub3, reference of pointer passed to function\n");
  printf("      Pointer to pointer varpp points to address        :   varpp = %p = a2\n",   varpp);
  printf("      Address contained at that location is             :  *varpp = %p = a1\n",  *varpp);
  printf("      Value at that address is the final distination    : **varpp = %d\n"     , **varpp);
  printf("      Pointer to pointer varpp address (only used here) :  &varpp = %p = a6\n",  &varpp);
}
void c_sub4(int *varpv)
{
  printf("\n");
  printf("   c_sub4, value of pointer passed to function\n");
  printf("      Pointer varpv points to address                   :   varpv = %p = a1\n",   varpv);
  printf("      Value at that address is the final distination    :  *varpv = %d\n"     ,  *varpv); 
  printf("      varpv address (only used here)                    :  &varpv = %p = a7\n",  &varpv);
}

