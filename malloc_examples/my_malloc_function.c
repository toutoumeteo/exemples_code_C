//http://stackoverflow.com/questions/1398307/how-can-i-allocate-memory-and-return-it-via-a-pointer-parameter-to-the-calling

#include <stdio.h>
#include <stdlib.h>

void my_function(int *ptr);
void apm_alloc(int **ptr);

int main()
{
  int *ptr;
  float *ptrf;
  
  apm_alloc(&ptr);
  ptrf = malloc(sizeof(*ptr));

  ptr[0]=1;
  ptr[1]=2;
  *ptrf=2;

  printf("%s %p\n", "Pointer int   value=", ptr);
  printf("%s %p\n", "Pointer float value=", ptrf);
  printf("%s %d %d\n", "Value int  =", ptr[0],ptr[1]);
  printf("%s %f\n", "Value float=", *ptrf);

  my_function(ptr);  
  
  free(ptr);
  free(ptrf);
}

void apm_alloc(int **ptr)
{
  // Pas certain de sizeof(**ptr)
  *ptr = malloc(2*sizeof(**ptr));
  return;
}

void my_function(int *ptr)
{
  printf("%s %d %d\n", "In function my_function, value int  =", ptr[0],ptr[1]); 
  return;
}
