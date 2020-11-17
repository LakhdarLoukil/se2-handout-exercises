#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/* Problème des lecteurs/rédacteurs, cas de priorité des lecteurs (readers) sur les rédacteurs (writers) */

#define NBRW 10 //Nombre de lecteurs/rédacteurs

sem_t mutex, writeblock;
int data = 0, nbreaders = 0;

void *reader_func(void *arg)
{
  long f;
  f = ((long)arg);
  sem_wait(&mutex);
  nbreaders = nbreaders + 1;
  if(nbreaders == 1)
    sem_wait(&writeblock);
  sem_post(&mutex);
  printf("La donnée lue par le lecteur %ld est %d\n", f, data);
  sleep(1);
  sem_wait(&mutex);
  nbreaders = nbreaders - 1;
  if(nbreaders == 0)
    sem_post(&writeblock);
  sem_post(&mutex);
  pthread_exit(0);
}

void *writer_func(void *arg)
{
  long f;
  f = ((long) arg);
  sem_wait(&writeblock);
  data++;
  printf("La donnée écrite par le rédacteur %ld est %d\n", f, data);
  sleep(1);
  sem_post(&writeblock);
  pthread_exit(0);
}

int main()
{
  long i; 
  pthread_t readers[NBRW],writers[NBRW];
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);
  for(i = 0; i < NBRW; i++)
  {
    pthread_create(&writers[i], NULL, writer_func, (void *)i);
    pthread_create(&readers[i], NULL, reader_func, (void *)i);
  }
  
  for(i = 0; i < NBRW; i++)
  {
    pthread_join(writers[i], NULL);
    pthread_join(readers[i], NULL);
  }
  return 0;
}
