#include "../include/sortMethods.hpp"
#include "../include/memlog.hpp"
#include <iostream>

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
            if (weigth[j] < weigth[min_idx] || (weigth[j] == weigth[min_idx] && vertices[j] < vertices[min_idx])) {
                min_idx = j;
            }
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

int partition(int *vertices, int *weigth, int *connection, int low, int high){
    int pivot = weigth[high];
    int i = low - 1;

    for(int j = low; j <= high; j++){
        if(weigth[j] < pivot || (weigth[j] == pivot && vertices[j] < vertices[high])){
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

void quickSort(int *vertices, int *weigth, int *connection, int low, int high){
    if(low < high){
        int pi = partition(vertices, weigth, connection, low, high);
        quickSort(vertices, weigth, connection, low, pi - 1);
        quickSort(vertices, weigth, connection, pi + 1, high);
    }
}


void merge(int *vertices, int *weigth, int *connection, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArrayWeigth = new int[subArrayOne], *rightArrayWeigth = new int[subArrayTwo];
    auto *leftArrayVertice = new int[subArrayOne], *rightArrayVertice = new int[subArrayTwo];
    auto *leftArrayConnection = new int[subArrayOne], *rightArrayConnection = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++) {
        leftArrayWeigth[i] = weigth[left + i];
        leftArrayVertice[i] = vertices[left + i];
        leftArrayConnection[i] = connection[left + i];
    }
    for (auto j = 0; j < subArrayTwo; j++) {
        rightArrayWeigth[j] = weigth[mid + 1 + j];
        rightArrayVertice[j] = vertices[mid + 1 + j];
        rightArrayConnection[j] = connection[mid + 1 + j];
    }

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArrayWeigth[indexOfSubArrayOne] <= rightArrayWeigth[indexOfSubArrayTwo]) {
            weigth[indexOfMergedArray] = leftArrayWeigth[indexOfSubArrayOne];
            vertices[indexOfMergedArray] = leftArrayVertice[indexOfSubArrayOne];
            connection[indexOfMergedArray] = leftArrayConnection[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            weigth[indexOfMergedArray] = rightArrayWeigth[indexOfSubArrayTwo];
            vertices[indexOfMergedArray] = rightArrayVertice[indexOfSubArrayTwo];
            connection[indexOfMergedArray] = rightArrayConnection[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        weigth[indexOfMergedArray] = leftArrayWeigth[indexOfSubArrayOne];
        vertices[indexOfMergedArray] = leftArrayVertice[indexOfSubArrayOne];
        connection[indexOfMergedArray] = leftArrayConnection[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    delete[] leftArrayWeigth; delete[] rightArrayWeigth;
    delete[] leftArrayVertice; delete[] rightArrayVertice;
    delete[] leftArrayConnection; delete[] rightArrayConnection;
}

void mergeSort(int *vertices, int *weight, int *connection, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(vertices, weight, connection, begin, mid);
    mergeSort(vertices, weight, connection, mid + 1, end);
    merge(vertices, weight, connection, begin, mid, end);
}

void heapify(int *vertices, int *weigth, int *connection, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && (weigth[l] > weigth[largest] || (weigth[l] == weigth[largest] && vertices[l] > vertices[largest]))) {
        largest = l;
    }
    if (r < n && (weigth[r] > weigth[largest] || (weigth[r] == weigth[largest] && vertices[r] > vertices[largest]))) {
        largest = r;
    }
    if (largest != i) {
        swap(vertices, i, largest);
        swap(weigth, i, largest);
        swap(connection, i, largest);
        heapify(vertices, weigth, connection, n, largest);
    }
}

void heapSort(int *vertices, int *weigth, int *connection, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(vertices, weigth, connection, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(vertices, 0, i);
        swap(weigth, 0, i);
        swap(connection, 0, i);
        heapify(vertices, weigth, connection, i, 0);
    }
}

void mySort(int *vertices, int *weigth, int *connection, int n) {
    int s = 0, b = 0, l = 0, r = n - 1;
    bool * aux = new bool[n];
    for (int j = 0; j <= n/2; j++){
        for (int i = l + 1; i <= r; i++){
            LEMEMLOG((long int)(&(vertices[i])), sizeof(double), vertices[i]);
            LEMEMLOG((long int)(&(vertices[b])), sizeof(double), vertices[b]);
            LEMEMLOG((long int)(&(vertices[s])), sizeof(double), vertices[s]);
            if(weigth[i] > weigth[b] && !aux[i]){
                b = i;
            } else if(weigth[i] < weigth[s] && !aux[i]) {
                s = i;
            }
        }
        swap(vertices, l, s);swap(vertices, r, b);
        swap(weigth, l, s); 
        ESCREVEMEMLOG((long int)(&(vertices[s])), sizeof(double), vertices[s]);
        ESCREVEMEMLOG((long int)(&(vertices[l])), sizeof(double), vertices[l]);
        swap(weigth, r, b);
        ESCREVEMEMLOG((long int)(&(weigth[b])), sizeof(double), weigth[b]);
        ESCREVEMEMLOG((long int)(&(weigth[r])), sizeof(double), weigth[r]);
        swap(connection, l, s); swap(connection, r, b);
        aux[s] = true; aux[b] = true;
        l++; r--; s = l, b = r;
    }
    delete[] aux;
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
        bool *verifier = new bool[p];
        
        for (int j = 0; j < connection[i]; j++) {
            int k;
            for (k = 0; k < n; k++) {
                if (vertices[k] == grafo[v][j]) {
                    break;
                }
            }
            if (weigth[k] < p){
                verifier[weigth[k] - 1] = true;
            }
        }
        if (!conditionCheck(verifier, p - 1)) {
            cout << 0 << endl; 
            //delete[] verifier;
            return;
        }
        delete[] verifier;
    }
    if (n != 0)
        printArray(vertices, n);
    else
        cout << 0 << endl;
}