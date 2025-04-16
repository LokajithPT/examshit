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
    else {
      val += burst[i];
      printf("process no %d \t burst time %d \t time taken %d \n" , i+1 , burst[i] , val);
    }
  }
  return 0;
}
