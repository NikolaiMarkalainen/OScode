#include <stdio.h>
#include <pthread.h>

int main()
{

pthread_t t1,t2;

void *print_msg(void *);

pthread_create(&t1, NULL, print_msg,(void*)"Hello ");
pthread_create(&t2, NULL, print_msg,(void*)"World!");
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}


void *print_msg(void *m){
char *cp = (char*) m;
printf("%s",m);
fflush(stdout);
sleep(1);
return NULL;
}


