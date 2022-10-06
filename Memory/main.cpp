#include <iostream>
#include <vector>

int main(){

std::vector <int> arr;

for(int i = 1; i < 11; i++){
	arr.push_back(i);
}
for(int i: arr){
	std::cout << i << std::endl;

}
for(int i: arr){
	std::cout << &i << std::endl;

}

	return 0;


}
