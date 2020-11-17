#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main (){
	pid_t pid ; 
	printf("Je suis le processus %d\n", getpid()); 
	sleep(10); 
	printf("Appel de fork.\n"); 
	pid = fork(); 
	printf("fork() retourne %d\n", pid); 
	sleep(10); 
	return 0; 
}