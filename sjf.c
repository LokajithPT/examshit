#include <stdio.h>

int main(){
  int burst[] = {5,1,6,7};
  int n = 4 ; 
  int i , j ; 
  int time = 0;
  for(i = 0 ; i< n-1 ; i++ ){
    for(j = i+1 ; j<n ; j ++){
      if (burst[j] < burst[i]) {  
      
      int temp = burst[i];
      burst[i] = burst[j];
      burst[j] = temp;
    }

    }
  }
  

  for(i = 0 ; i < n ; i++){
    time += burst[i];
    printf("%d %d \n ",burst[i] , time);
  }

}
