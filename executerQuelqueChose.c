#define NB_ITERS 5
	
void executerQuelqueChose (void){
	for (int i = 0; i < NB_ITERS; i++){
		printf("i = %d\n", i);
		sleep(rand()%4);
	}
}
