#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Compile with -pthread

int sum = 0; //shared
pthread_mutex_t lock;
// mutex variable
void *countgold(void *param) {
    // timing the for loops for mutex
    pthread_mutex_lock(&lock);
  int i; //local to each thread
  for (i = 0; i < 10000000; i++) {
    sum += 1;
  }
    pthread_mutex_unlock(&lock);
  return NULL;
}

int main() {
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, countgold, NULL);
  pthread_create(&tid2, NULL, countgold, NULL);
  //Wait for both threads to finish:
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  //destroying set mutex variable
    pthread_mutex_destroy(&lock);
  printf("ARRRRG sum is %d\n", sum);
  return 0;
}
