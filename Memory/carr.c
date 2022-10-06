#include <stdio.h>
#include <stdlib.h>

int main(){
int* ptr;
int n = 10; 
int i;

printf("Enter number of elements:");
printf("Entered number of elements: %d\n", n);

ptr = (int*)malloc(n* sizeof(int));

if(ptr == NULL){
	printf("Memory not allocated.\n");
	exit(0);
}

else{
	printf("Memory successfully allocated.\n");

	for(i = 0; i < n; i++){
		ptr[i] = i +1;
	}

	printf("The elements of the array are: " );
	
	for(i=0; i<n; i++){
		printf("%d, ", ptr[i]);
		}
}


free(ptr);
printf("\nMemory freed.\n");

return 0;

}
