#include "fun.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int calcularFatorialRecursivo(long long int n)
// Descricao: calcular o fatorial de n (n!)
// Entrada: n
// Saida: n!
{
  if(n <= 1) return 1;
  else return n * calcularFatorialRecursivo(n-1);
  
}

long long int calcularFatorialIterativo(long long int n)
// Descricao: calcular o fatorial de n (n!)
// Entrada: n
// Saida: n!
{
  long long int num = 1;
  for(int i = 1; i <= n; i++) num = num * i;
  return num;
}

long long int calcularFibonacciRecursivo(long long int n)
// Descricao: calcula o n-esimo termo da sequencia fibonacci
// Entrada: n
// Saida: n-esimo termo da sequencia de fibonacci
{
  if(n <= 2) return 1;
  else return calcularFibonacciRecursivo(n-1) + calcularFibonacciRecursivo(n-2);
}

long long int calcularFibonacciIterativo(long long int n)
// Descricao: calcula o n-esimo termo da sequencia fibonacci
// Entrada: n
// Saida: n-esimo termo da sequencia de fibonacci
{
  long long int a = 0, b = 1, c;
    int i = 2;
    if(n == 1) return a;
    else{
        if(n == 2) return b;
        else{
            while(i < n){
                c = a + b;
                a = b;
                b = c;
                i++;
            }
            return c;
        }
    }
}