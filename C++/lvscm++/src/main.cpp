#include <iostream>${lib ? '
#include "' lib '.hpp"
' : }

int main(${args ? 'int argc, char **argv' : 'void'}) {
    ${hw ? lib ?
    'std::string str("World");
    say_hello(str);'
    : 'std::cout << "Hello World!" << std::endl;' : }
}
