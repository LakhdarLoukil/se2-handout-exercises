#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int i;
int main (){
  i = 1;
  pid_t pid;
  pid = getpid();
  printf("Avant fork: Je suis le processus main, mon pid est = %d\n",pid);
  sleep(20); 
  printf("Appel de fork par le processus main de PID = %d...\n", getpid());
  pid = fork(); // Clonage du processus
  switch(pid) {
	case -1:   // pid = -1: erreur du fork()
			fprintf(stderr,"erreur du fork.\n");
			exit(1);
			break;

	case 0:    // pid = 0 : on est dans le fils
			fprintf(stdout,"Fork reussi... Je suis le processus fils cree par fork: mon PID est = %d, le PID de mon pere est = %d\n",getpid(),getppid());
			sleep(30); 
			fprintf (stdout,"Fin du fils (PID=%d), i=%d...\n",getpid(), i);
			exit (0);
			break;

	default:   // pid > 0 : on est dans le pere 
			// Modification de la variable i par le pere
			i = 2;
			fprintf (stdout,"Je suis le processus pere, je viens de modifier la variable i, i= %d\n", i);
			sleep (10);
			printf ("Fin du pere (PID=%d), i = %d...\n",getpid(), i);
			exit (0);
			break;
	}
}