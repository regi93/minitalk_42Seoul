#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main(int argc, char *argv[]) 
{ 
	printf("PID = %d\n", getpid()); 
	printf("부모 PID = %d\n", getppid()); 
	return 0; 
}

