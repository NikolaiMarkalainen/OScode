#include <iostream>
#include <vector>
#include <algorithm>
#include <pthread.h>
#include <stdio.h>
#define MAX_NO_OF_THREADS 10
#define MAX_NO_OF_ELEMENTS 100000000
pthread_mutex_t lock;
static int arr[MAX_NO_OF_ELEMENTS];
static long long int sum;

typedef struct arg_data{
    int thread_number;
} arg_data;


void *countgold(void* arg) {
    pthread_mutex_lock(&lock);
    arg_data* current_thread_data = (arg_data*) arg;
    printf("Current thread no is : %d\n", current_thread_data->thread_number);
    int endpart = (current_thread_data->thread_number) * (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);
    int startpart = endpart - (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);
    printf("Here we will sum %d to %d\n", arr[startpart], arr[endpart - 1]);
    long long int current_thread_sum = 0;
    for (int i = startpart; i < endpart; i++) {
        current_thread_sum += arr[i];
    }
    sum += current_thread_sum;
    pthread_mutex_unlock(&lock);
    return NULL;
};


int main(int argc,const char* argv[]) {
    //std::vector<int> arr;
    clock_t start,end;
    double cpu_time_taken;

    pthread_t id[MAX_NO_OF_THREADS];
    arg_data arg_arr[MAX_NO_OF_THREADS];
    for(int i = 0; i < MAX_NO_OF_ELEMENTS; i++ ){
        arr[i] = i+1;
    }
    std::cout << "Creating "<< MAX_NO_OF_THREADS << " Threads" << std::endl;

    start=clock();

    int thread_no = 1;
    for(thread_no = 1; thread_no <= MAX_NO_OF_THREADS; thread_no++){
        arg_arr[thread_no-1].thread_number = thread_no;
        pthread_create(&id[thread_no -1 ], NULL, countgold, &arg_arr[thread_no-1]);
    }
    for(int i = 1; i <= MAX_NO_OF_THREADS; i++){
        pthread_join(id[i-1], NULL);
    }
    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time taken to sum all the numbers are " <<  cpu_time_taken << std::endl;

    std::cout << "If you want to see last 100 values press 1" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Else press 0 " << std::endl;

    int argum;
    std::cin >> argum;
    size_t n = sizeof(arr)/sizeof(arr[0]);
    std::cbegin(arr),std::cend(arr);
    switch(argum){
        case 0:
            return 0;
        case 1:
            for(int i = 99999900; i < 100000000; i++){
                std::cout << arr[i] << std::endl;
            }
            break;
    }
    return 0;
}

