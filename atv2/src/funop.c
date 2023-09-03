#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include "fun.h"

struct rusage usage;

typedef long long int(*Operacao)(long long int);

long long int resultOp(int n, Operacao op){
    return op(n);
}

void result(int n, Operacao op, Operacao op2){

    struct timespec t1, t2;
    struct rusage b, e;

    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &b);

    resultOp(n, op);
    
    getrusage(RUSAGE_SELF, &e);
    clock_gettime(CLOCK_MONOTONIC, &t2);

    long int sec, nsec;

    if (t2.tv_nsec < t1.tv_nsec){
	nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
	sec = t2.tv_sec-t1.tv_sec-1;
    } else {
	nsec = t2.tv_nsec-t1.tv_nsec;
	sec = t2.tv_sec-t1.tv_sec;
    }

    printf("   Tempo de relógio gasto para calcular recursivamente: %ld secs / %ld nano-secs\n", sec, nsec);
    printf("   Tempo de usuário gasto para calcular recursivamente: %ld secs / %ld nano-secs\n", e.ru_stime.tv_sec - b.ru_stime.tv_sec, e.ru_stime.tv_usec - b.ru_stime.tv_usec);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &b);

    resultOp(n, op2);
    
    getrusage(RUSAGE_SELF, &e);
    clock_gettime(CLOCK_MONOTONIC, &t2);

    if (t2.tv_nsec < t1.tv_nsec){
	nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
	sec = t2.tv_sec-t1.tv_sec-1;
    } else {
	nsec = t2.tv_nsec-t1.tv_nsec;
	sec = t2.tv_sec-t1.tv_sec;
    }

    printf("   Tempo de relógio gasto para calcular iterativamente: %ld secs / %ld nano-secs \n", sec, nsec);  
    printf("   Tempo de usuário gasto para calcular iterativamente: %ld secs / %ld nano-secs\n\n", e.ru_stime.tv_sec - b.ru_stime.tv_sec, e.ru_stime.tv_usec - b.ru_stime.tv_usec);


}

int main(int argc, char* argv[]){

    if(argc != 2){
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    printf("   Valor sendo calculado: %d\n\n", n);

    printf(" - FATORIAL - \n\n");
    printf("   Valor: %lld\n", resultOp(n, calcularFatorialRecursivo));
    result(n, calcularFatorialRecursivo, calcularFatorialIterativo);

    printf(" - FIBONACCI - \n\n");
    printf("   Valor: %lld\n", resultOp(n, calcularFibonacciRecursivo));
    result(n, calcularFibonacciRecursivo, calcularFibonacciIterativo);
    
    fatorialDuploRecursivo(30);

    return 0;
}