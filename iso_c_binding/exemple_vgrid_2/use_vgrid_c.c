#include "vgrid.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  TVGrid *vgd;

  vgd = VGD_New();
  
  VGD_Print(vgd);

  return 0;
}
