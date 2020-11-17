#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h>

#define NUMTHREADS   8 
#define VECTOR_SIZE  100

int vect1[VECTOR_SIZE], vect2[VECTOR_SIZE];
int result = 0; //variable partagée par les threads et utilisée pour cumuler les produits scalaires partiels calculés par les threads

int seq_scalar_product (int u[], int v[], int n);

void *sum_vect_block(void *threadid) { 
   long tid; 
   tid = (long)threadid; 
   /* Compléter la fonction du thread */
   





   pthread_exit(0); 
} 

int main (int argc, char *argv[]) { 
   pthread_t threads[NUMTHREADS]; 
   int rc; 
   long th; 
   double begin, end, exec_time;

   srand(time(NULL));

   for (int i = 0; i < VECTOR_SIZE; ++i)
   {
      vect1[i] = rand()%VECTOR_SIZE;
      vect2[i] = rand()%VECTOR_SIZE;
   }

   printf("Le produit scalaire séquentiel de vect1 par vect2 est = %d\n", seq_scalar_product(vect1, vect2, VECTOR_SIZE));
   begin = clock();
   for(th = 0; th < NUMTHREADS; th++){ 
      rc = pthread_create(&threads[th], NULL, afficheHello, (void *)th); 
      if (rc){ 
         printf("Erreur de creation de thread; code erreur = %d\n", rc); 
         exit(-1); 
      } 
   } 

   for(th = 0; th < NUMTHREADS; th++){ 
      pthread_join(threads[th], NULL); 
   } 
   end = clock();
   exec_time = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("Le produit scalaire parallèle de vect1 par vect2 est = %d, temps d'execution = %lf\n", result, exec_time);
   pthread_exit(0); 
}

   
int seq_scalar_product (int u[], int v[], int n) {
   int sum = 0;
      for (int i = 0; i < n; i++) {
         sum += u[i] * v[i];
      }
      return sum;
   }
