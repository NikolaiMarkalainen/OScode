#include <iostream>

int main(int argc, const char** argv){

int i = 0;

std::cout << "Komentoriviargumentteja: " << + argc - 1 << std::endl;

std::cout << "Ja ne ovat: " << std::endl;
for(int x = 1; x < argc; x++){

std::cout << argv[x] << std::endl;

}

return 0;


}
