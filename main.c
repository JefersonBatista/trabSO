#include <stdio.h>
#include <unistd.h>

int main() {
	char programa[51];
	char argv[2][51];
	
	printf("nsh> ");
	
	scanf("%s", programa);
	argv[0] = "./";
	argv[0][2] = programa;
	execvp(programa, NULL);
	
	return 0;
}


