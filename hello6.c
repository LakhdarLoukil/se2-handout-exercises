#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	for (int i = 1; i <= 2; ++i) {
		pid = fork();
		if (pid == 0)
		  break; // Fin de la boucle for
		else
		  printf("Hello!\n");
	}
	return 0;
}
