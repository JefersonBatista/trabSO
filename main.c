#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	char *argv[2];
	char program[51], path[51];
	
	int pid;

	while(1) {
		printf("nsh> ");
		scanf("%s", program);
		
		if(strcmp(program, "exit") == 0)
			return 0;
			
		pid = fork();
		if(pid == 0) {
			argv[0] = (char*) calloc(strlen(program)+1, sizeof(char));
			strcpy(argv[0], program);
			argv[1] = NULL;
			
			path[0] = '.';
			path[1] = '/';
			path[2] = '\0';
			strcat(path, program);
			execvp(path, argv);
		}
		
		if(pid != 0)
			wait(NULL);
	}
}


