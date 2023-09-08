#include <stdlib.h>

struct Matrix {
    int rows, cols;
    int** data;
};

int main() {
    int i;
    struct Matrix* rotation3D;

    // Aloca memória para a estrutura Matrix
    rotation3D = (struct Matrix*)malloc(sizeof(struct Matrix));

    rotation3D->rows = 4;
    rotation3D->cols = 4;

    // Aloca memória para a matriz de inteiros
    rotation3D->data = (int**)malloc(sizeof(int*) * rotation3D->rows);
    for (i = 0; i < rotation3D->rows; i++) {
        rotation3D->data[i] = (int*)malloc(sizeof(int) * rotation3D->cols);
    }

    // Libera a memória alocada para a matriz de inteiros
    for (i = 0; i < rotation3D->rows; i++) {
        free(rotation3D->data[i]);
    }
    free(rotation3D->data);

    // Libera a memória alocada para a estrutura Matrix
    free(rotation3D);

    return 0;
}
