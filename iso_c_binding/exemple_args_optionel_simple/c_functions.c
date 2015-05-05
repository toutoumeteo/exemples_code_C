// Andre Plante mai 2015

#include <stdio.h>

void c_optional(int man, int *opt)
{
  // NULL pointer indicate unused optional argument

  printf("   In c_optional\n");
  printf("      man = %d\n",man);

  printf("      opt pointing to = %p\n", opt);
  if(opt) {
    printf("      Applying *opt = %d\n",*opt);
  } else {
    printf("      Not Applying option\n");
  }

}
