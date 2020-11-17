#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5 		// taille du buffer
#define NB_PRODS 4
#define NB_CONS 4

int buffer[SIZE]; 	// buffer des produits (valeurs) 
int tail = 0, head = 0; 	// indices de tete et de queue du buffer 

// semaphores representant respectivement le nombre de places libres et le nombre de produits 
sem_t empty, products;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *producer(void* threadid) { // fonction producteur
	long tid = ( long ) threadid ;
	int valeur;
	do { // produire une valeur (produit) jusqu'a ce que la valeur est 0
		int valeur = rand() % 100; // generer une valeur aleatoire entre 0 et 99
		printf("Le producteur %ld produit > %d\n", tid, valeur);
		sem_wait(&empty); // attendre une place libre dans le buffer
		pthread_mutex_lock(&mutex);
		buffer[tail] = valeur; // inserer une nouvelle valeur dans le buffer
		tail = (tail + 1) % SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&products); // incrementer le nombre de produits dans le buffer
		sleep(rand() % 5); // marquer une pose de duree aleatoire (entre 0 et 4s) apres la production
	}
	while(valeur);
	pthread_exit(NULL); // terminer le thread producteur
}

void *consumer(void* threadid) { //fonction consommateur
	long tid = ( long ) threadid ;
	int valeur;
	do { // consomme une valeur (produit) jusqu'a ce que la valeur consommee est 0
		sem_wait(&products); // attendre pour des produits dans le buffer
		pthread_mutex_lock(&mutex);
		valeur = buffer[head]; // prendre la valeur d'indice head dans le buffer 
		head = (head + 1) % SIZE;
		pthread_mutex_unlock(&mutex);
		printf("\tLe consommateur %ld consomme < %d\n", tid, valeur);
		sem_post(&empty); // incrementer le nombre de places libres dans le buffer
		sleep(rand() % 5); // simuler la consommation du produit
	} while(valeur);
	pthread_exit(NULL); // terminer le thread consommateur
}

int main(int argc, char *argv[]) {
	// declaration des threads producteur et consommateur
	pthread_t prods[NB_PRODS], cons[NB_CONS];
	srand(time(0)); // initialiser le generateur de nombres aleatoires 
	// initialiser les semaphores 
	sem_init(&empty, 0, SIZE);
	sem_init(&products, 0, 0);
	int rc;
	// creer les threads producteur et consommateur 
	for(long int i = 0; i < NB_PRODS; i++){ 
		rc = pthread_create(&prods[i], NULL, producer, (void*)i); 
		if (rc){ 
			printf("Erreur de creation du thread.\n"); 
			exit(-1); 
		} 
	} 
	for(long int i = 0; i < NB_CONS; i++){ 
		rc = pthread_create(&cons[i], NULL, consumer, (void*)i); 
		if (rc){ 
			printf("Erreur de creation du thread.\n"); 
			exit(-1); 
		} 
	}
	// attendre la terminaison des threads producteur et consommateur 
	for (int i = 0; i < NB_CONS; ++i)
	{
		pthread_join(cons[i], NULL);
	}

	for (int i = 0; i < NB_PRODS; ++i)
	{
		pthread_join(prods[i], NULL);
	}
	// detruire les semaphores 
	sem_destroy(&empty);
	sem_destroy(&products);
	return 0;
}
