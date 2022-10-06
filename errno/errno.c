#include <errno.h>
#include <stdio.h>
#include <string.h>
int main(){

FILE * fp;

	fp = fopen("text.txt", "r");
	printf("Value of errno: %d\n ", errno);
	printf("Error message by errno : %s\n",strerror(errno));
	perror("Message from perror: ");
	printf("For more information check documentation at man errno\n");
	return 0;
}
