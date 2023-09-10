#include <stdlib.h>
    #include <stdio.h>

    int main(void) {
        int *p;

        while (1) {
            p = malloc(128); // Aloque memória
            printf("%ld\n", (long)p);
            free(p); // Libere a memória alocada
        }

        return 0;
    }