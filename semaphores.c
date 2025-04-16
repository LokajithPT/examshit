#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t sem ; 

void* threadf(void * arg ){
  sem_wait(&sem);
  printf("thread %d: in critical section \n " , *(int*)arg);
  sleep(1);
  printf("thread %d: leving critical section " , *(int*)arg);
  sem_post(&sem);
  return NULL;
}


int main() 
{
  pthread_t t1 , t2 ; 

  int id1 = 1 , id2 = 2 ; 
  sem_init(&sem , 0 ,1 );

  pthread_create(&t1 , NULL , threadf , &id1);

  pthread_create(&t2 , NULL , threadf , &id2);
  pthread_join(t1 , NULL);  
  pthread_join(t2 , NULL);  

  sem_destroy(&sem);


  return 0;
}
