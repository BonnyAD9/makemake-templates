#include <stdio.h>

int main(${args ? 'int argc, char **argv' : 'void'}) {
    ${hw ? 'printf("Hello World!\\n");' : }
}
