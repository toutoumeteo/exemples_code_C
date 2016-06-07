/* Example using memcmp by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
  int result, i, n=50;

  float example1[n];
  float example2[n];

  for(i=0; i < n; i++){
    example1[i]=i;
    example2[i]=i;
  }

  example2[n-1]=0.;

  result = memcmp(example1, example2, n*sizeof(float)/sizeof(char));

  if (result == 0){
    printf("Arrays are the same\n");
  } else {
    printf("Arrays are different\n");       
  }

  return 0;

}

