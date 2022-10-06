#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	printf("EXEC2.C\n");
	printf("PID of exec 2 = %d", getpid());
	return 0;

}
