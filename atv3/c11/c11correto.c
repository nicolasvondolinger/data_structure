#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char *msg = malloc(10); 

    strcpy(msg, "Holberton");
    msg[0] = 'R';
    printf("%ld, %s\n", (long)getpid(), msg);

    free(msg); // Libere a memória alocada
    return 0;
}
