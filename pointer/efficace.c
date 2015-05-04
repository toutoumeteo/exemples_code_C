#include <stdio.h>
#include <stdlib.h>

int VGD_FindIp1Idx     (int Ip1, int *Lst, int Size);
//int VGD_FindIp1Idx_lent(int Ip1, int *Lst, int Size);

int main()
{
  int i, ip1, ind;
  int size = 1000;
  int trial = 1000000;
  int *ptr = malloc(size*sizeof(*ptr));  

  for( i=0; i < size; i++) {
    ptr[i] = i;
  }
  ip1=size-1;
  //while(trial--){
  //  ind=VGD_FindIp1Idx(ip1,ptr,size);
  //}
  while(trial--){
    ind=VGD_FindIp1Idx_lent(ip1,ptr,size);
  }
  printf("    %d\n",ind);
  
  return 0;
}

int VGD_FindIp1Idx(int Ip1, int *Lst, int Size)
{
  int idx=0;
  
  while( Size-- ) {
    if( *Lst++ == Ip1 )
      return idx;
    ++idx;
  }
  
  return(-1);
}

int VGD_FindIp1Idx_lent(int Ip1, int *Lst, int size)
{
  int i;

  for( i=1; i< size; i++) {
    if( Lst[i] == Ip1 )
      return i;
  }
  
  return(-1);
}
