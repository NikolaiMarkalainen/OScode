#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	if(strcmp(argv[1], "ls")== 0){
	char* args[2];
	args[0] = "/usr/bin/ls";
	args[1] = argv[2];
	args[2] = NULL;
	printf("Main functions on \n");
	execvp(args[0],args);
		if(execv(args[0], args) == -1){
		perror("Error in calling exec!");
		}
	}
	else if(strcmp(argv[1], "echo") == 0){
	char* args[3];
	args[0] = "/bin/echo";
	args[1] = argv[2];
	args[2] = NULL;
	printf("Echo function on\n");
	execv(args[0],args);
		if(execvp(args[0],args) == -1){
		perror("Error in calling exec!");
		}
	}
}
