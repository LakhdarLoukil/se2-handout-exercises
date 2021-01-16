#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void fonctionThread(void){ 
	pthread_t mon_tid; 
	mon_tid = pthread_self(); 
	int i, nbreIters; 
	nbreIters = rand()%100; 
	i = 0; 
	printf("Thread (0x)%x : DEBUT\n", (int)mon_tid);  
	while(i < nbreIters) i++; 
	printf("Thread (0x)%x : FIN\n", (int)mon_tid); 
	pthread_exit(NULL); 
}
