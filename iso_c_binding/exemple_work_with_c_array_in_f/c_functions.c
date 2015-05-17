#include <stdlib.h>
int  *make_array(int n_elements) {
  int *parray;
  int i;
  parray = (int*) malloc(n_elements * sizeof(int));
  for (i = 0; i < n_elements; i++) {
    parray[i] = i+1;
  }
  return parray;
}
