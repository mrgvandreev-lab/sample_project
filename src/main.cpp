#include <iostream>
#include <stdexcept>
#include <string>
#include "add.hpp"
int main(int argc, char *argv[]){
    if (argc!=3){
        std::cerr <<"Exactly 2 arguments required\n";
        return 1;
    }
    int a, b;
    try {
        a = std::stoi(argv[1]);
        b = std::stoi(argv[2]);
    } catch (const std::exception &) {
        std::cerr << "Arguments must be integer numbers\n";
        return 1;
    }
    std::cout << add(a,b) << '\n';
    return 0;
}
