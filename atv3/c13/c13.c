#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p;

    p = (char *)malloc(19);

    free(p); // Libere a primeira alocação de memória
    p = (char *)malloc(12);

    free(p); // Libere a segunda alocação de memória
    p = (char *)malloc(16);

    free(p); // Libere a terceira alocação de memória

    return 0;
}
