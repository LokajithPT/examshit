#include <stdio.h>
#include <string.h>

int main(){

  int nof , n;
  char name[20];
  int start , end ; 

  printf("how many files are ya planing :");
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++ ){
    printf("name of file :");
    scanf("%s",&name);
    printf("gimme da start and end block :");
    scanf("%d %d" , &start , &end);
    printf("the blocks are \n");
    for(int i = start ; i < end ; i++){
      printf("%d\t" , i);
    }
  }
}
