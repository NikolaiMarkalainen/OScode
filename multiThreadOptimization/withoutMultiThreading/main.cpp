#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
int main(int argc, const char* argv[]) {
    clock_t start,end;
    double cpu_time_taken;
    start = clock();
    std::cout << "Starting to count to 100 m" << std::endl;
    std::vector<int> arr;
    for(int i = 0; i < 100000000; i++){
        arr.push_back(i);
    }
    reverse(arr.begin(),arr.end());
    if(argc > 1){
        if(argv[1] == std::string("-s")){
            for (int i = 0; i < 100; i++){
                arr[i];
            }
            end = clock();
            cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            std::cout << "Time taken to sum all the numbers are " <<  cpu_time_taken << std::endl;
        }
    }
    else{
        for(int i = 0; i < 100; i++){
            std::cout << arr[i] << std::endl;
        }
        end = clock();
            cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            std::cout << "Time taken to sum all the numbers are " <<  cpu_time_taken << std::endl;
    }
}
