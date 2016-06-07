/* Example using memcmp by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
  int result, i, n=50;

  double example1[n];
  double example2[n];

  for(i=0; i < n; i++){
    example1[i]=i;
    example2[i]=i;
  }

  example2[0]=1.;

  result = memcmp(example1, example2, n*sizeof(double)/sizeof(char));

  if (result == 0){
    printf("Arrays are the same\n");
  } else {
    printf("Arrays are different\n");       
  }

  return 0;

}

