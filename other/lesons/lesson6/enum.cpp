#include <iostream> 

enum Status {WA, OK = 99, CE};

union parameter {
    double pi;
    short int number;
};

int main(){
    int x = 100;
    if (x == Status::WA){
        std::cout << "Wrong Answer!" << std::endl;
    } else if (x == Status::CE){
        std::cout << "Compitation Error!" << std::endl;
    } else if (x == Status::OK){
        std::cout << "OK!" << std::endl;
    }
    parameter example;
    example.number = -10000;
    std::cout << example.pi << ' ' << example.number << std::endl;
    example.pi = 3.1415;
    std::cout << example.pi << ' ' << example.number << std::endl;

    return 0;
}