#include <stdio.h>

void c_sub(int var1, int *var2)
{

  printf("   In c_sub   var1 =  %d\n",  var1);
  printf("   In c_sub  &var1 =  %p\n", &var1);
  printf("   In c_sub   var2 =  %p\n",  var2);
  printf("   In c_sub  &var2 =  %p\n", &var2);
  printf("   In c_sub  *var2 =  %d\n", *var2);


}
