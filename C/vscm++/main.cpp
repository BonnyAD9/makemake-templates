#include <iostream>

int main(${args ? 'int argc, char **argv' : 'void'}) {
    ${hw ? 'std::cout << "Hello World!" << std::endl;' : }
}
