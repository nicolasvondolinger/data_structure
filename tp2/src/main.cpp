#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

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
            if (weigth[j] < weigth[min_idx]) min_idx = j;
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
        int keyWeigth = weigth[i];
        int keyVertices = vertices[i];
        int keyConnection = connection[i];
        int j = i - 1;

        while (j >= 0 && weigth[j] > keyWeigth) {
            swap(vertices, j, j+1);
            swap(weigth, j, j+1);
            swap(connection, j, j+1);
            j--;
        }
        weigth[j+1] = keyWeigth;
        vertices[j+1] = keyVertices;
        connection[j+1] = keyConnection;
    }
}

int partition(int *vertices, int *weigth, int *connection, int n, int low, int high){
    int pivot = weigth[high];
    int i = low - 1;

    for(int j = low; j <= high; j++){
        if(weigth[j] < pivot){
            i++;
            swap(weigth, i, j);
            swap(vertices, i, j);
            swap(connection, i, j);
        }
    }
    swap(weigth, i+1, high);
    swap(connection, i+1, high);
    swap(vertices, i+1, high);
    return i+1;
}

void quickSort(int *vertices, int *weigth, int *connection, int n, int low, int high){
    if(low < high){
        int pi = partition(vertices, weigth, connection, n, low, high);
        quickSort(vertices, weigth, connection, n, low, pi -1);
        quickSort(vertices, weigth, connection, n, pi+1, high);

    }
}

void merge(int *vertices, int *weigth, int *connection, int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for(auto i = 0; i < subArrayOne; i++){
        leftArray[i] = weigth[left + 1];
    }
    for(auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = weigth[mid + 1 + j];
    }

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    
}

void mergeSort(int *vertices, int *weigth, int *connection, int end, int begin){
    if(begin >= end) return;

    int mid = begin + (end - begin) / 2;
    mergeSort(vertices, weigth, connection, mid, begin);
    mergeSort(vertices, weigth, connection, end, mid + 1);
    merge(vertices, weigth, connection, begin, mid, end);
}

void heapify(int *vertices, int *weigth, int *connection, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && weigth[l] > weigth[largest]) largest = l;
    if(r < n && weigth[r] > weigth[largest]) largest = r;
    if(largest != i){
        swap(vertices, i, largest);
        swap(weigth, i, largest);
        swap(connection, i, largest);

        heapify(vertices, weigth, connection, n, largest);
    }
}

void heapSort(int *vertices, int *weigth, int *connection, int n){
    for(int i = (n/2) - 1; i >= 0; i--) heapify(vertices, weigth, connection, n, i);

    for(int i = n -1; i> 0; i--){
        swap(vertices, 0, i);
        swap(weigth, 0, i);
        swap(connection, 0, i);

        heapify(vertices, weigth, connection, i, 0);
    }
}

int getMax(int * arr, int n){
    int max = arr[0];
    for(int i = 1; i < n; i++)if(arr[i] > max){
        max = arr[i];
    }
    return max;
}

void mySort(int *vertices, int *weigth, int *connection, int n) {
    int max = getMax(weigth, n);

    int outputWeigth[n], outputVertices[n], outputConnection[n];
    int count[n]; 

    for (int i = 0; i < 10; i++) count[i] = 0; 

    for (int i = 1; max / i > 0; i *= 10) {
        for (int j = 0; j < n; j++)
            count[(weigth[j] / i) % 10]++;
        for (int j = 1; j < n; j++)
            count[j] += count[j - 1];
        for (int j = n - 1; j >= 0; j--) {
            outputWeigth[count[(weigth[j] / i) % 10] - 1] = weigth[j];
            outputVertices[count[(weigth[j] / i) % 10] - 1] = vertices[j];
            outputConnection[count[(weigth[j] / i) % 10] - 1] = connection[j];
            count[(weigth[j] / i) % 10]--;
        }
        for (int j = 0; j < n; j++){
            weigth[j] = outputWeigth[j];
            connection[j] = outputConnection[j];
            vertices[j] = outputVertices[j];
        }
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
            quickSort(vertices, weigth, connection, n, 0, n-1);
            colorCheck(grafo, vertices, weigth, connection, n);
            break;
        case 'm':
            mergeSort(vertices, weigth, connection, n - 1, 0);
            printArray(weigth, n);
            //colorCheck(grafo, vertices, weigth, connection, n);
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

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    //cout << "Tempo: " << duration.count() << " ms" << endl;

    for (int i = 0; i < n; i++) {
        delete[] grafo[i];
    }
    delete[] grafo;
    delete[] vertices;
    delete[] weigth;
    delete[] connection;

    return 0;
}
