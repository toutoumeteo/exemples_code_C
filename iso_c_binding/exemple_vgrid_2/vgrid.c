#include "vgrid.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Constants
#define MAX_DESC_REC 10000
#define MAX_VKIND    100

// Macros
#define FREE(x) if(x) { free(x); x=NULL; }

/*----------------------------------------------------------------------------
 * Nom      : <VDG_FindIp1Idx>
 * Creation : Avril 2015 - E. Legault-Ouellet - CMC/CMOE
 *
 * But      : Trouver l'index d'un ip1 dans une liste d'ip1
 *
 * Parametres :
 *  <Ip1>   : Paramètres de l'application
 *  <Lst>   : La référence verticale
 *  <Size>  : Header RPN
 *
 * Retour   : L'index de l'ip1 dans la liste ou -1 si pas trouvé
 *
 * Remarques :
 *
 *----------------------------------------------------------------------------
 */
int VGD_FindIp1Idx(int Ip1,int *Lst,int Size) {
   int idx=0;

   while( Size-- ) {
      if( *Lst++ == Ip1 )
         return idx;
      ++idx;
   }

   return(-1);
}

/*----------------------------------------------------------------------------
 * Nom      : <MemInit>
 * Creation : Avril 2015 - E. Legault-Ouellet - CMC/CMOE
 *
 * But      : Initialise un array de double à une valeur donnée
 *
 * Parametres :
 *  <Arr>   : L'array à initialiser
 *  <Val>   : La valeur à laquelle initialiser l'array
 *  <Size>  : La taille de l'array
 *
 * Retour   : 
 *
 * Remarques :
 *
 *----------------------------------------------------------------------------
 */
void VGD_MemInit(double *Arr,double Val,int Size) {
   while( Size-- )
      *Arr++ = Val;
}

void VGD_Print(TVGrid *VGrid) {
  if( VGrid ) {
    printf("ptop_8 = %f\n",VGrid->ptop_8);
  } else {
    printf("TVGrid is NULL");
  }
}

/*----------------------------------------------------------------------------
 * Nom      : <VGD_New>
 * Creation : Avril 2015 - E. Legault-Ouellet - CMC/CMOE
 *
 * But      : Initialise et retourne une structure de type TVGrid
 *
 * Parametres :
 *
 * Retour   : Une structure initialisée de type TVGrid
 *
 * Remarques :
 *
 *----------------------------------------------------------------------------
 */
TVGrid *VGD_New() {
   TVGrid *vgrid = malloc(sizeof(TVGrid));

   if( vgrid ) {
      vgrid->ptop_8        = VGD_MISSING;
      vgrid->pref_8        = VGD_MISSING;
      vgrid->table         = NULL;
      vgrid->a_m_8         = NULL;
      vgrid->b_m_8         = NULL;
      vgrid->a_t_8         = NULL;
      vgrid->b_t_8         = NULL;
      vgrid->ip1_m         = NULL;
      vgrid->ip1_t         = NULL;
      vgrid->rcoef1        = VGD_MISSING;
      vgrid->rcoef2        = VGD_MISSING;
      vgrid->initialized   = 0;
      vgrid->valid         = 0;
      vgrid->ip1           = 0;
      vgrid->ip2           = 0;
      vgrid->ref_name      = strdup("None");

      vgrid->rec.initialized = 0;
      strcpy(vgrid->rec.ETIKET,"            ");
      strcpy(vgrid->rec.NOMVAR,"    ");
      strcpy(vgrid->rec.TYPVAR,"  ");
   }

   return vgrid;
}

/*----------------------------------------------------------------------------
 * Nom      : <VGD_Free>
 * Creation : Avril 2015 - E. Legault-Ouellet - CMC/CMOE
 *
 * But      : Libère la mémoire d'une structure de type TVGrid
 *
 * Parametres :
 *    <VGrid>  : Structure dont il faut libérer la mémoire
 *
 * Retour   :
 *
 * Remarques :
 *
 *----------------------------------------------------------------------------
 */
void VGD_Free(TVGrid *VGrid) {
  printf("\tDans VGD_free cote C, VGrid = %p\n",VGrid);
  //printf("\tDans VGD_free cote C, (*VGrid)->a_m_8 = %p\n",(*VGrid)->a_m_8);
   if( VGrid ) {
      FREE(VGrid->table);
      FREE(VGrid->a_m_8);
      FREE(VGrid->b_m_8);
      FREE(VGrid->a_t_8);
      FREE(VGrid->b_t_8);
      FREE(VGrid->ip1_m);
      FREE(VGrid->ip1_t);
      FREE(VGrid->ref_name);

      printf("\tfreeing\n");
      free(VGrid);
      VGrid = NULL;
      printf("\tDans VGD_free cote C, VGrid = %p\n",VGrid);
   }
}
void VGD_Free2(TVGrid **VGrid) {
  printf("\tDans VGD_free2 cote C, *VGrid = %p\n",*VGrid);
  //printf("\tDans VGD_free2 cote C, (*VGrid)->a_m_8 = %p\n",(*VGrid)->a_m_8);
   if( *VGrid ) {
      FREE((*VGrid)->table);
      FREE((*VGrid)->a_m_8);
      FREE((*VGrid)->b_m_8);
      FREE((*VGrid)->a_t_8);
      FREE((*VGrid)->b_t_8);
      FREE((*VGrid)->ip1_m);
      FREE((*VGrid)->ip1_t);
      FREE((*VGrid)->ref_name);

      printf("\tfreeing\n");
      free(*VGrid);
      *VGrid = NULL;
      printf("\tDans VGD_free2 cote C, *VGrid = %p\n",*VGrid);
   }
}

