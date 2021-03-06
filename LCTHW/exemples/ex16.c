#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define APM_OK 1
#define APM_ERROR 0

typedef struct Person {
  char *name;
  int age;
  int height;
  int weight;
  char init;
} Person;

Person *Person_create(char *name, int age, int height, int weight)
{
  Person *who = malloc(sizeof(Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;
  who->init = 1;
  return who;

}

int Person_destroy(Person *who)
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

void Person_print(Person *who)
{
  if(who->init != 1){
    printf("Person is not constructed, cannot print\n");
    return;
  }
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);  
  printf("\tinit: %d\n", who->init);  
}

int main()
{

  Person *joe = Person_create("Joe Alex", 32, 64, 140);
  //Person *andre;

  Person_print(joe);

  if(Person_destroy(joe) == APM_ERROR){
    printf("Error free joe\n");
    return(1);
  }

  // This produces an error since andre was never constructed.
  //Person_print(andre);
  //if(Person_destroy(andre) == APM_ERROR){
  //  printf("Error free andre\n");
  //  return(1);
  //}

  return 0;
  
}
