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

void swap(int *arr, int position){
    int aux = arr[position];
    arr[position] = arr[position + 1];
    arr[position + 1] = aux;
}

void bubbleSort(int *vertices, int *weigth, int *connection, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (weigth[j] > weigth[j + 1]) {
                swap(weigth, j);
                swap(vertices, j);
                swap(connection, j);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void setFalse(bool * arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = false;
    }
}

bool conditionCheck(bool * arr, int n){
    for(int i = 0; i < n; i++){
        if(!arr[i]) return false;
    }
    return true;
}

void colorCheck(int **grafo, int *vertices, int *weigth, int *connection, int n) {
    for (int i = 0; i < n; i++) {
        int v = vertices[i], p = weigth[i]; bool verifier[p - 1];
        setFalse(verifier, p - 1);
        for (int j = 0; j < connection[i]; j++) {
            int k;
            for(k = 0; k < n; k++) {
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
        } else if (i+1 == n) printArray(vertices, n);
    }
}

int main() {
    char op; int n; cin >> op >> n;

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
        int p; cin >> p;
        weigth[i] = p;
    }

    switch (op) {
        case 'b':
            bubbleSort(vertices, weigth, connection, n);
            //cout << "vertices: "; printArray(vertices, n);
            //cout << "weigth: "; printArray(weigth, n);
            //cout << "connection: "; printArray(connection, n);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        default:
            cout << "ERROR";
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
