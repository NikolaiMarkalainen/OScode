#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	printf("PID of exec.c = %d \n", getpid());
	char *args[] = {"Hello", "Haha", "HehE", NULL};
	execv("./exec2", args);
	printf("Back to ex1.c");
	return 0;

}
