# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <omp.h>

int main () {

  int i,j, size = 10000;
  double ff, id;

  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

# pragma omp parallel for private(i,j,ff)
  for( i = 0; i < size; i++){
    for( j = 0; j < size; j++){
      ff = sin(i);
    }
  }

  return(0);
}
