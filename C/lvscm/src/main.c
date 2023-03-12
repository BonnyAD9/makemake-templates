#include <stdio.h>${lib ? '
#include "' lib '.h"
' : }

int main(${args ? 'int argc, char **argv' : 'void'}) {
    ${hw ? lib ?
    'say_hello("World");'
    : 'printf("Hello World!\\n");' : }
}
