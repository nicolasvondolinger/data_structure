#include <stdlib.h>

void f(void) {
    int* x = malloc(10 * sizeof(int));
    x[9] = 0; // Acessando o último elemento válido do array.
    free(x); 
}

int main(void) {
    f();
    return 0;
}
