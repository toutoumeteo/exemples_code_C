#include <stdio.h>

void print_vec_element(float element)
{
  printf("      element = %f\n",element);
}

c_recieve_vec(float *vecp, int vsize)
{
  
  printf("\n   In c_recieve_vec\n");
  printf("   Address in vecp is : vecp = %p\n",vecp);
  int k;
  for( k = 0; k < vsize; k++)
    {
      printf("    k = %d, vecp[k] = %f\n", k, vecp[k]);
    }
  printf("\n");
}


