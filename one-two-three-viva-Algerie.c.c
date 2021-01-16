#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 
#include <semaphore.h> 
#include <pthread.h> 

void func1(void){ 
  for (int i = 0; i < 4; i++){ 
    sleep(rand()%5); 
    printf("One, "); 
  } 
  pthread_exit(0); 
} 

void func2(void){ 
  for (int i = 0; i < 4; i++){ 
	 sleep(rand()%5); 
	 printf("Two, "); 
  } 
  pthread_exit(0); 
} 

void func3(void){ 
  for (int i = 0; i < 4; i++){ 
	 sleep(rand()%5); 
	 printf("Three, "); 
  } 
  pthread_exit(0); 
} 

void func4(void){ 
for (int i = 0; i < 4; i++){ 
	sleep(rand()%5); 
	printf("Viva l'Algérie.\n"); 
} 
pthread_exit(0); 
} 

int main(){ 
pthread_t th1, th2, th3, th4; 

srand(time(NULL)); 

if(pthread_create(&th1, NULL, (void*) func1, NULL)){
	fprintf(stderr,"thread1"); 
	exit(EXIT_FAILURE); 
} 

if(pthread_create(&th2, NULL, (void*) func2, NULL)){
	fprintf(stderr,"thread2"); 
	exit(EXIT_FAILURE); 
} 

if(pthread_create(&th3, NULL, (void*) func3, NULL)){
	fprintf(stderr,"thread3"); 
	exit(EXIT_FAILURE); 
} 

if(pthread_create(&th4, NULL, (void*) func4, NULL)){
	fprintf(stderr,"thread4"); 
	exit(EXIT_FAILURE); 
} 
pthread_join(th1,NULL); 
pthread_join(th2,NULL); 
pthread_join(th3,NULL); 
pthread_join(th4,NULL);  
pthread_exit(0); 
}		
