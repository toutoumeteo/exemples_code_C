#include <stdio.h>
#include <string.h>

long long reverseLongLong (char *c) {
  // from http://www.ibm.com/developerworks/aix/library/au-endianc/
  long long lf;
  char *p = (char *)&lf;
  
  p[0] = c[7];
  p[1] = c[6];
  p[2] = c[5];
  p[3] = c[4];
  p[4] = c[3];
  p[5] = c[2];
  p[6] = c[1];
  p[7] = c[0];
  
  return lf;
}



int main() {

  char *valc8 = "12345678";
  long long ival8;
  double *rval8;
  FILE *fp;

  rval8 = (double*)valc8;
  printf("valc8 = '%s', *rval8 = %f\n", valc8, *rval8);
  ival8 = reverseLongLong(valc8);  
  valc8 = (char *)&ival8;
  rval8 = (double*)&ival8;
  printf("reversed valc8 = '%s', *rval8 = %f\n", valc8, *rval8);

  fp = fopen("ip.txt", "w");
  fwrite(rval8, sizeof(double), 1, fp);
  fclose(fp);
 
  fp = fopen("ip.txt", "r");
  fread(rval8, sizeof(double), 1, fp);
  fclose(fp);
  valc8 = (char *)&ival8;
  printf("From file valc8 = '%s', *rval8 = %f\n", valc8, *rval8);

}
