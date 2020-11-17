#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

#define NUMTHREADS 10 

int mat[NUMTHREADS][NUMTHREADS];
int vect[NUMTHREADS];	// vect[i] contiendra la somme des éléments de la ligne i de mat.


// Fonction du thread
void sommeLigne(void *i) { 
	  /* Compléter la fonction du thread */
   





	pthread_exit(0); 
} 


int main (int argc, char *argv[]) { 
	pthread_t threads[NUMTHREADS]; 
	int rc; 
	long th; 
	int sommeMatrice = 0;

	srand(time(NULL));
	
	/* Initialisation aléatoire de la matrice matr. */
	for (int i = 0; i < NUMTHREADS; ++i)
	{
		for (int j = 0; j < NUMTHREADS; ++j)
		{
			mat[i][j] = (int) rand()%20;
		}
	}

	printf("Matrice:\n");
	for (int i = 0; i < NUMTHREADS; ++i)
	{
		for (int j = 0; j < NUMTHREADS; ++j)
		{
			printf("%d  ", mat[i][j]);
		}
		printf("\n");
	}

	/* Calcul séquentiel de la somme des éléments de la matrice mat. */
	for (int i = 0; i < NUMTHREADS; ++i)
	{
		for (int j = 0; j < NUMTHREADS; ++j)
		{
			sommeMatrice += mat[i][j];
		}
		printf("\n");
	}
	printf("Somme séquentielle: %d\n", sommeMatrice);


	/* Création et démarrage des threads */
	for(th = 0; th < NUMTHREADS; th++){ 
		//printf("main: creation du thread %ld\n", th); 
		rc = pthread_create(&threads[th], NULL, (void *) 	sommeLigne, (void *)th); 
		if (rc){ 
			printf("Erreur de creation de thread; code erreur = %d\n", rc); 
			exit(-1); 
		} 
	} 

	/* Jointure des threads */
	for (int th = 0; th < NUMTHREADS; ++th)
	{
		pthread_join(threads[th], NULL);
	}

	sommeMatrice = 0;
	for (int i = 0; i < NUMTHREADS; ++i)
	{
		sommeMatrice += vect[i];
	}
	printf("Somme parallèle = %d\n", sommeMatrice);
	pthread_exit(0); 
}
