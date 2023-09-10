#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *buf;

int sum_to_n(int num)
{
    int i, sum = 0;
    for (i = 1; i <= num; i++)
        sum += i;
    return sum;
}

void printSum()
{
    char line[10];
    printf("enter a number:\n");
    fgets(line, 10, stdin);
    if (line != NULL)
        strtok(line, "\n");
    buf = (char *)malloc(20); // Aloque memória para buf
    sprintf(buf, "sum=%d", sum_to_n(atoi(line)));
    printf("%s\n", buf);
    free(buf); // Libere a memória alocada para buf
}

int main(void)
{
    printSum();
    return 0;
}
