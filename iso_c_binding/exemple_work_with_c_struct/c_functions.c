// Exemple base sur LCTHW http://c.learncodethehardway.org/book/ex16.html
//    et sur code d'Eric Legault-Ouellet

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define APM_OK 1
#define APM_ERROR 0

typedef struct Person {
  float *name;
  int age;
  int height;
  int weight;
  char init;
} Person;

Person *C_Person_create()
{
  Person *who = malloc(sizeof(Person));
  assert(who != NULL);

  who->name = NULL;
  who->age = 0;
  who->height = 0;
  who->weight = 0;
  who->init = 1;
  return who;

}

int C_Person_destroy(Person *who)
{
  //assert(who != NULL);
  if(who->init != 1){
    printf("ERROR in Person_destroy: Person is not constructed\n");
      return(APM_ERROR);
  }

  free(who->name);
  free(who);

  return(APM_OK);
}

void C_Person_print(Person *who)
{
  if(who->init != 1){
    printf("Person is not constructed, cannot print\n");
    return;
  }
  printf("Name: %p\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);  
  printf("\tinit: %d\n", who->init);  
}
