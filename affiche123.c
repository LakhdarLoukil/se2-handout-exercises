#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 
#include <pthread.h> 

void *affiche1() { 
	for(int i = 0; i < 10; i++) {
		printf("1"); 
 	}
	pthread_exit(0); 
}

void *affiche2() { 
	for(int i = 0; i < 10; i++) {
		printf("2"); 
	}
	pthread_exit(0); 
} 

void *affiche3() { 
	for(int i = 0; i < 10; i++) {
		printf("3"); 
	}
	pthread_exit(0); 
} 

int main(){ 
	pthread_t th1, th2, th3; 
	srand(time(NULL)); 
	
	if(pthread_create(&th1, NULL, affiche1, NULL)){ 
		fprintf(stderr,"thread1"); 
		exit(EXIT_FAILURE); 
	} 
	
	if(pthread_create(&th2, NULL, affiche2, NULL)){ 
		fprintf(stderr,"thread2"); 
		exit(EXIT_FAILURE); 
	} 

	if(pthread_create(&th3, NULL, affiche3, NULL)){ 
		fprintf(stderr,"thread3"); 
		exit(EXIT_FAILURE); 
	} 

	pthread_join(th1,NULL); 
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);  
	exit(EXIT_SUCCESS); 
}
