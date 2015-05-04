#include <stdio.h>
#include <stdlib.h>

void print_ptr(int *ptr, int size);

int main()
{
  int i;
  int size = 10;
  int *ptr = malloc(size*sizeof(*ptr));  

  for( i=0; i < size; i++) {
    ptr[i] = 100 + i;
  }
  printf("Avant print_ptr, ptr[0] = %d\n",ptr[0]);
  printf("Avant print_ptr, &ptr   = %p\n",&ptr);
  printf("Avant print_ptr, *ptr   = %d\n",*ptr);
  printf("Avant print_ptr, &size  = %p\n",&size);
  print_ptr(ptr,size);
  printf("Apres print_ptr, ptr[0] = %d\n",ptr[0]);
  
  return 0;
}

void print_ptr(int *ptr, int size)
{
  printf("   &ptr   = %p Par le meme pointer que dans main\n",&ptr);
  printf("   *ptr   = %d mais il pointe a la meme chose\n",*ptr);
  printf("   &size  = %p\n",&size);
  while( size-- ) {
    printf("      taille %d\n", size);
    printf("      *ptr++   = %d\n", *ptr++);
    printf("      ptr[-1]  = %d\n",ptr[-1]);
    printf("      &ptr     = %p L'addresse du pointer ne change pas\n",&ptr);
  }
}
