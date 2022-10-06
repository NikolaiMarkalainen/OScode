#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	pid_t p1 = fork();
	char* binaryPath ="/bin/";
	char *arg1 = argv[1];
	char *arg2 = argv[2];
	char *args[] = {argv[1], argv[2], NULL};	
/*
	for (int i = 1; i < argc; i++){
		printf("%s", argv[i]);
	}	
*/
if(p1 == 0){
	printf("Moving to /bin/ with execv\n");
	printf("\n");
	sleep(1);
	return 0;
}
pid_t w_pid1 = wait(NULL);
	if(w_pid1 == -1) 
	{
	exit(0);
	}
	if(w_pid1> 0){
		execv(binaryPath,args);
		printf(binaryPath,"%d", args[0]);
	}

}
