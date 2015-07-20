#include <stdio.h>
#include <string.h>

void reverseDouble (double *ff) {
  char *c = (char*)(ff);
  double lff;
  char *p = (char *)&lff;
  p[0] = c[7];
  p[1] = c[6];
  p[2] = c[5];
  p[3] = c[4];
  p[4] = c[3];
  p[5] = c[2];
  p[6] = c[1];
  p[7] = c[0];
  //printf("c = '%s'\n", c);
  //printf("p = '%s'\n", p);
  //printf("lff = %f\n", lff);
  //printf("*ff = %f\n", *ff);
  *ff = lff;
  
}

int main() {

  char *valc8 = "ABCDEFGH", *c2 = "12345678";
  double rval8, *ptr_d;
  FILE *fp;

  ptr_d = (double*)(valc8);
  rval8 = *ptr_d;
  c2 = (char*)(&rval8);
  printf("c2 = '%s'\n", c2);
  reverseDouble(&rval8);

  printf("reversed c2 = '%s'\n", c2);
  printf("reversed valc8 = '%s'\n", valc8);

/*   fp = fopen("ip.txt", "w"); */
/*   fwrite(&rval8, sizeof(double), 1, fp); */
/*   fclose(fp); */
 
/*   fp = fopen("ip.txt", "r"); */
/*   fread(&rval8, sizeof(double), 1, fp); */
/*   fclose(fp); */
/*   valc8 = (char *)&rval8; */
/*   printf("From file valc8 = '%s', rval8 = %f\n", valc8, rval8); */

  return(0);

}
