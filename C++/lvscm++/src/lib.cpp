#include "${lib}.hpp"${hw ? '

#include <iostream>
#include <string>

void say_hello(std::string &str) {
    std::cout << "Hello " << str << "!" << std::endl;
}' : }
