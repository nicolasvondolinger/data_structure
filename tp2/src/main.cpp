#include <iostream>

#include "../include/sortMethods.hpp"

using namespace std;

int main() {

    char op; int n; cin >> op >> n;

    int **grafo = new int *[n];
    int *vertices = new int[n];
    int *weigth = new int[n];
    int *connection = new int[n];

    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
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
        int p;
        cin >> p;
        weigth[i] = p;
    }

    switch (op) {
        case 'b':
            bubbleSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            cout << "weigth: "; printArray(weigth, n);
            cout << "vertices: "; printArray(vertices, n);
            cout << "connection: "; printArray(connection, n);
            break;
        case 's':
            selectionSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'i':
            insertionSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'q':
            quickSort(vertices, weigth, connection, 0, n-1);
            colorCheck(grafo, vertices, weigth, connection, n);
            cout << "weigth: "; printArray(weigth, n);
            cout << "vertices: "; printArray(vertices, n);
            cout << "connection: "; printArray(connection, n);
            break;
        case 'm':
            mergeSort(vertices, weigth, connection, 0, n -1);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'p':
            heapSort(vertices, weigth, connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'y':
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
    delete[] grafo;
    delete[] vertices;
    delete[] weigth;
    delete[] connection;

    return 0;
}
