#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i;int *a = (int*)malloc(sizeof(int) * 10);
    if (!a) {
        perror("malloc failed");
        return -1;
    }
    for (i = 0; i < 10; i++) {
        a[i] = i;
    }
    free(a);
    return 0;
}
