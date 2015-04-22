#include <stdio.h>
#include <stdlib.h>

const int VGD_OK = 1;
const int VGD_ERROR = 0;

struct Vgrid_descriptor
{
  int vcode,kind,version,nk;
  double *a_m_8;
};

void null_descrip(struct Vgrid_descriptor *vgd);
void print_descrip(struct Vgrid_descriptor  vgd);
void set_vcode(struct Vgrid_descriptor *vgd);
int alloc_descrip(struct Vgrid_descriptor *vgd, int nk);

int main()
{
  int i;
  struct Vgrid_descriptor vgd;

  null_descrip(&vgd);
  print_descrip(vgd);

  vgd.kind=5;
  vgd.version=2;

  set_vcode(&vgd);
  print_descrip(vgd);

  if ( alloc_descrip(&vgd,10) == VGD_ERROR ){
    printf("Problem allocating vgd\n");
    exit(1);
  }

  print_descrip(vgd);
  
}

void print_descrip(struct Vgrid_descriptor vgd)
{
  int i,nk;
  printf("= Vgrid descriptor information =======\n");
  printf("kind    = %d\n",vgd.kind);
  printf("version = %d\n",vgd.version);
  printf("vcode   = %d\n",vgd.vcode);
  if(vgd.a_m_8){
    printf("a_m_8\n");
     for (i=0; i < vgd.nk; i++){
      printf("%f\n",vgd.a_m_8[i]);
    }
  }
  printf("=====================================\n");
}

void set_vcode(struct Vgrid_descriptor *vgd)
{
  vgd->vcode = vgd->kind * 1000 + vgd->version;
}

int alloc_descrip(struct Vgrid_descriptor *vgd, int nk)
{
  int i;
  vgd->nk = nk;
  vgd->a_m_8 = (double*)malloc(nk * sizeof(double));
  if(vgd->a_m_8 == NULL){
    printf("Cannot allocate a_m_8 of size %d\n",nk);
    return VGD_ERROR;
  }
  for (i=0; i<10; i++){
    vgd->a_m_8[i]=i;
    printf("%f\n",vgd->a_m_8[i]);
  }
  return VGD_OK;
}

void null_descrip(struct Vgrid_descriptor *vgd)
{
  vgd->kind    = 0;
  vgd->version = 0;
  vgd->vcode   = 0;
  vgd->nk      = 0;
  vgd->a_m_8   = NULL;
}
