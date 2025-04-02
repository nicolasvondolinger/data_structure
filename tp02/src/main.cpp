#include <iostream>

#include "../include/sortMethods.hpp"
#include "../include/memlog.hpp"

using namespace std;

int main() {

    char op; int n; cin >> op >> n;

    int **grafo = new int *[n];
    int *vertices = new int[n];
    int *weigth = new int[n];
    int *connection = new int[n];

    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        connection[i] = j;
        grafo[i] = new int[j];
        for (int k = 0; k < j; k++) {
            int num;
            cin >> num;
            grafo[i][k] = num;
        }
        vertices[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        weigth[i] = p;
    }

    char lognome[100] = "/tmp/greedy.out";
    int regmem = 1;

    iniciaMemLog(lognome);

    if(regmem) ativaMemLog();
    else desativaMemLog();

    defineFaseMemLog(0);
    switch (op) {
        case 'b':
            defineFaseMemLog(0);
            bubbleSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 's':
            defineFaseMemLog(0);
            selectionSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'i':
            defineFaseMemLog(0);
            insertionSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'q':
            defineFaseMemLog(0);
            quickSort(vertices, weigth, connection, 0, n-1);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'm':
            defineFaseMemLog(0);
            mergeSort(vertices, weigth, connection, 0, n -1);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'p':
            defineFaseMemLog(0);
            heapSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'y':
            defineFaseMemLog(0);
            mySort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida: 'b' (Bubble Sort), 's' (Selection Sort), 'i' (Insertion Sort), 'q' (Quick Sort), 'm' (Merge Sort), 'p' (Heap Sort), ou 'y' (Seu Algoritmo)." << endl;
            break;
    }

    for (int i = 0; i < n; i++) {
        delete[] grafo[i];
    }
    delete[] grafo; delete[] vertices; delete[] weigth; delete[] connection;

    return 0;
}
