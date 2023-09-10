#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b) {
    int c;
    c = a / b;
    return 0;
}

int calc() {
    int a;
    int b;
    a = 13;
    b = 1;
    return actual_calc(a, b); // Retorna o resultado da função actual_calc
}

int main() {
    int result = calc();
    return 0;
}
