#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  // go through each string in argv
  // why am I skipping argv[0]?

  printf("Program name is %s\n", argv[0]);

  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }

  // Let's make our own array of strings
  char *states[] = {
    "California", "Oregon",
    "Washington", "Texas"
  };
  int num_states = 4;
  
  i = 0;
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }
  
  return 0;
  
}
