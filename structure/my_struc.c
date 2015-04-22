#include <stdio.h>
#include <stdlib.h>

struct Vgrid_descriptor
{
  int vcode,kind,version;
  double *a_m_8;
};

void print_descrip(struct Vgrid_descriptor  vgd);
void set_vcode(struct Vgrid_descriptor *vgd);
void alloc_descrip(struct Vgrid_descriptor *vgd, int nk);

int main()
{
  int i;
  double *a_m_8;
  struct Vgrid_descriptor vgd;

  vgd.kind=5;
  vgd.version=2;

  set_vcode(&vgd);
  print_descrip(vgd);

  alloc_descrip(&vgd,10);
  for (i=0; i<10; i++){
    printf("%f\n",vgd.a_m_8[i]);
  }
  
}

void print_descrip(struct Vgrid_descriptor vgd)
{
  printf("kind    = %d\n",vgd.kind);
  printf("version = %d\n",vgd.version);
  printf("vcode   = %d\n",vgd.vcode);
}

void set_vcode(struct Vgrid_descriptor *vgd)
{
  vgd->vcode = vgd->kind * 1000 + vgd->version;
}

void alloc_descrip(struct Vgrid_descriptor *vgd, int nk)
{
  int i;
  vgd->a_m_8 = (double*)malloc(nk * sizeof(double));
  for (i=0; i<10; i++){
    vgd->a_m_8[i]=i;
    printf("%f\n",vgd->a_m_8[i]);
  }
}
