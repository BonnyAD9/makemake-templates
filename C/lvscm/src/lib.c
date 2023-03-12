#include "${lib}.h"${hw ? '

#include <stdio.h>

void say_hello(char *str) {
    printf("Hello %s!\\n", str);
}' : }
