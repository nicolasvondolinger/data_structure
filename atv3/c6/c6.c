#include <stdlib.h>
#include <stdint.h>

struct _List {
    int32_t* data;
    int32_t length;
};
typedef struct _List List;

List* resizeArray(List* array) {
    int32_t* dPtr = array->data;
    dPtr = realloc(dPtr, 15 * sizeof(int32_t)); // Realoca memória

    // Verifique se a realocação foi bem-sucedida
    if (dPtr == NULL) {
        return array;
    }

    // Atualize o ponteiro de dados da estrutura List
    array->data = dPtr;
    return array;
}


int main() {
    List* array = calloc(1, sizeof(List));
    array->data = calloc(10, sizeof(int32_t));
    array = resizeArray(array);

    free(array->data);
    free(array);
    return 0;
}
