#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

#define N 10 /* Dimension de la matrice et nombre de threads à démarrer */

int mat[N][N];
int vect[N];	// vect[i] contiendra la somme des éléments de la ligne i de mat.


// Fonction du thread
void sommeLigne(void *i) { 
	  /* Compléter la fonction du thread */
   





	pthread_exit(0); 
} 


int main (int argc, char *argv[]) { 
	pthread_t threads[N]; 
	int rc; 
	long th; 
	int sommeMatrice = 0;

	srand(time(NULL));
	
	/* Initialisation aléatoire de la matrice matr. */
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = (int) rand()%20;
		}
	}

	printf("Matrice:\n");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d  ", mat[i][j]);
		}
		printf("\n");
	}

	/* Calcul séquentiel de la somme des éléments de la matrice mat. */
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			sommeMatrice += mat[i][j];
		}
		printf("\n");
	}
	printf("Somme séquentielle: %d\n", sommeMatrice);


	/* Création et démarrage des threads */
	for(th = 0; th < N; th++){ 
		//printf("main: creation du thread %ld\n", th); 
		rc = pthread_create(&threads[th], NULL, (void *) 	sommeLigne, (void *)th); 
		if (rc){ 
			printf("Erreur de creation de thread; code erreur = %d\n", rc); 
			exit(-1); 
		} 
	} 

	/* Jointure des threads */
	for (int th = 0; th < N; ++th)
	{
		pthread_join(threads[th], NULL);
	}

	sommeMatrice = 0;
	for (int i = 0; i < N; ++i)
	{
		sommeMatrice += vect[i];
	}
	printf("Somme parallèle = %d\n", sommeMatrice);
	pthread_exit(0); 
}
