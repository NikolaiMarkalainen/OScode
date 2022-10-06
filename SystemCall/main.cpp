#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    const size_t MAXIMUM_SIZE = 1;
    const char* path = "test.txt";
    // path for the file;
    int n, fd,fd2;
    // fd / fd2 holding open functions with respective flags
    // n holding read value of read function
    // write
    char* input = new char[MAXIMUM_SIZE];

    std::cout << "Enter value to add to the text file cant be larger than 1 byte: " << std::endl;
    n = read(0,input,MAXIMUM_SIZE);
    // I don't want my n: to read any filedescriptor I want to read it from the user:
    // then I want it to use my input as buffer char * and set the maximum size of it to 1 byte
    fd2 = open(path, O_CREAT| O_WRONLY, 0777);
    //open my file if it doesn't exist use O_CREAT flag to create it and set parameters to write only
    //set file using privileges to everyone
    write(fd2,input,n);
    // write into filedescriptor 2 and take buffer input char* and use read parameters of n
    int closing = close(fd2);
    if(closing == -1){
        // testing function's return value
        std::cout << "The errno number is: " << errno << std::endl;
        perror("The error message is : ");
        //printing needed error message incase function doesn't work.
    }
    else if(closing == 0){
        std::cout << "File closed successfully" << std::endl;
    }


    std::cout<<"The file contents are as followed: "<< std::endl;

    fd = open(path, O_RDONLY, 0777);
    //open my filedescriptor and set it to read only mode with all perms
    n = read(fd,input,MAXIMUM_SIZE);
    // set my n variable to hold the read parameters
    // reading from the file the buffer and limiting the reading to our limit.
    write(1,input,n);
    // write on the screen the buffer and my reading parameters which states file and rules
    closing = close(fd);

    if(closing == -1){
        // testing function's return value
        std::cout << ""<< std::endl;
        std::cout << "The errno number is: " << errno << std::endl;
        perror("The error message is : ");
    }
    else if(closing == 0){
        std::cout << ""<< std::endl;
        std::cout << "File closed successfully" << std::endl;
    }
}