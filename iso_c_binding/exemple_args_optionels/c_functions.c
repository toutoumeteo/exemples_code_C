// Andre Plante mai 2015

#include <stdio.h>

void c_optional(int F_i, float F_f, int *F_io, float *F_fo)
{
  // NULL pointer indicate unused optional arguments


  printf("   In c_optional\n");
  printf("      F_i = %d\n",F_i);
  printf("      F_f = %f\n",F_f);

  if(F_io) {
    printf("      *F_io = %d\n",*F_io);
  }

  
  if(F_fo){
    printf("      *F_fo = %f\n",*F_fo);
  }

}
