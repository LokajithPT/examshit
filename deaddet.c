#include <stdio.h>

int main(void)
{
  int burst[] = {3,6,8,10,12};
  int val = 4;
  for(int i = 0 ; i < 4 ; i++){
    if (burst[i] > val ) {
      printf("burst = %d \t avail = %d\n" , burst[i] , val);
      printf("deadlock detected ... gg\n");
      break;

    }
  }

  printf("there was no deadlock machan chillax \n");
  return 0;
}

