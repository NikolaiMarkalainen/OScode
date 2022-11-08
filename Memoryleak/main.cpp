#include <iostream>
using namespace std;

int main() {
    // testing stackoverflow and valgrid tool on linux
    int * a;
    a = new int[100000000];
    for (int i = 0; i < 10000000001; i++){
        a[i] = i+100;
    }
    return 0;
}
