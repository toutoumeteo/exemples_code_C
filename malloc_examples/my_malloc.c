#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = malloc(2*sizeof(*ptr));
  float *ptrf;
  
  printf("%s %p\n", "NULL from stdio = ", NULL);

  ptrf = malloc(sizeof(*ptrf));
  if ( ptrf == NULL){
    printf("%s\n","Cannot allocate ptrf, aborting");
    exit(1);     
  }
  
  ptr[0]=1;
  ptr[1]=2;
  *ptrf=2;

  printf("%s %p\n", "Pointer int   value=", ptr);
  printf("%s %p\n", "Pointer float value=", ptrf);
  printf("%s %d %d\n", "Value int  =", ptr[0],ptr[1]);
  printf("%s %d %d\n", "Value int  =", *ptr,*(ptr+1));
  printf("%s %f\n", "Value float=", *ptrf);
  
  free(ptr);
  free(ptrf);
}
