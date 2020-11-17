#include <stdio.h>
#include <unistd.h>

	int main() { 
		printf ("Hello!\n"); 
		fork(); 
		return 0; 
	}