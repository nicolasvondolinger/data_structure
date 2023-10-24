#include <iostream>

using namespace std;

const int MAX = 1000000;

void printArray(int *arr, int n) {
    cout << 1 << ' ';
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *vertices, int *weigth, int *connection, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (weigth[j] > weigth[j + 1]) {
                int aux = weigth[j];
                weigth[j] = weigth[j + 1];
                weigth[j + 1] = aux;

                aux = vertices[j];
                vertices[j] = vertices[j + 1];
                vertices[j + 1] = aux;

                aux = connection[j];
                connection[j] = connection[j + 1];
                connection[j + 1] = aux;

                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void colorCheck(int **grafo, int *vertices, int *weigth, int *connection, int n) {
    for (int i = 0; i < n; i++) {
        int v = vertices[i], p = weigth[i], count = weigth[i];
        for (int j = 0; j < connection[v]; j++) {
            int u = grafo[v][j];
            int k;
            for (k = 0; k < n; k++) {
                if (vertices[k] == u) {
                    break;
                }
            }
            if (weigth[k] < p) {
                count--;
                cout << v << " passou" << endl;
            }         
        }
        if (count > 1) {
            cout << v << ':' << i << ':' << count << endl;
            break;
        } else if (i+1 == n) printArray(vertices, n);
    }
}

int main() {
    char op; int n;
    cin >> op >> n;
    int **grafo = new int *[n];
    int *vertices = new int[n];
    int *weigth = new int[n];
    int *connection = new int[n];
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        connection[i] = j; grafo[i] = new int[j];
        for (int k = 0; k < j; k++) {
            int num; cin >> num;
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
            printArray(vertices, n);
            printArray(weigth, n);
            printArray(connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        default:
            cout << "ERROR";
            break;
    }

    // Libere a memória alocada
    for (int i = 0; i < n; i++) {
        delete[] grafo[i];
    }
    delete[] grafo;
    delete[] vertices;
    delete[] weigth;
    delete[] connection;

    return 0;
}
