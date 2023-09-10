#include <stdlib.h>
#include <stdint.h>

int main() {
    char* destination = calloc(27, sizeof(char));
    char* source = malloc(27 * sizeof(char)); // Alocar a mesma quantidade de elementos.

    for (uint8_t i = 0; i < 26; i++) {
        *(destination + i) = *(source + i); // Copiar os dados da origem para o destino.
    }

    *(destination + 26) = '\0'; // Null-terminate the destination string.

    free(destination);
    free(source);
    return 0;
}
