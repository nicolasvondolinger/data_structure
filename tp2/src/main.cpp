#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

const int MAX = 1000000;

void printArray(int *arr, int n) {
    cout << 1 << ' ';
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *arr, int a, int b) {
    int aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}

void bubbleSort(int *vertices, int *weigth, int *connection, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (weigth[j] > weigth[j + 1]) {
                swap(vertices, j, j + 1);
                swap(weigth, j, j + 1);
                swap(connection, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int *vertices, int *weigth, int *connection, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (vertices[j] < vertices[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            swap(vertices, min_idx, i);
            swap(weigth, min_idx, i);
            swap(connection, min_idx, i);
        }
    }
}

void insertionSort(int *vertices, int *weigth, int *connection, int n) {
    for (int i = 1; i < n; i++) {
        int key = vertices[i];
        int j = i - 1;

        while (j >= 0 && vertices[j] > key) {
            vertices[j + 1] = vertices[j];
            weigth[j + 1] = weigth[j];
            connection[j + 1] = connection[j + 1];
            j--;
        }
        vertices[j + 1] = key;
    }
}

void setFalse(bool *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = false;
    }
}

bool conditionCheck(bool *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (!arr[i]) return false;
    }
    return true;
}

void colorCheck(int **grafo, int *vertices, int *weigth, int *connection, int n) {
    for (int i = 0; i < n; i++) {
        int v = vertices[i], p = weigth[i];
        bool verifier[p - 1];
        setFalse(verifier, p - 1);
        for (int j = 0; j < connection[i]; j++) {
            int k;
            for (k = 0; k < n; k++) {
                if (vertices[k] == grafo[v][j]) {
                    break;
                }
            }
            if (weigth[k] < p) {
                verifier[weigth[k] - 1] = true;
            }
        }
        if (!conditionCheck(verifier, p - 1)) {
            cout << 0 << endl;
            break;
        } else if (i + 1 == n) printArray(vertices, n);
    }
}

int main() {

    auto start = chrono::high_resolution_clock::now();

    char op;
    int n;
    cin >> op >> n;

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
            cout << "quick";
            break;
        case 'm':
            cout << "mergesort";
            break;
        case 'p':
            cout << "heap";
            break;
        case 'y':
            cout << "your";
            break;
        default:
            cout << "ERROR";
            break;
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Tempo: " << duration.count() << " ms" << endl;

    for (int i = 0; i < n; i++) {
        delete[] grafo[i];
    }
    delete[] grafo;
    delete[] vertices;
    delete[] weigth;
    delete[] connection;

    return 0;
}
