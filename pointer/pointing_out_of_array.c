#include <stdio.h>
#define MAX 2

int main()
{

  int ff[MAX] = {1,2};
  int *prt;

  prt = ff;

  printf(" *prt++ is ok     : %d\n", *prt++);
  printf(" *prt++ is ok too : %d\n", *prt++);
  printf(" *prt++ is not ok : %d\n", *prt++);
  printf(" ff[2]  is not ok : %d\n", ff[2]);

  return 0;

}
