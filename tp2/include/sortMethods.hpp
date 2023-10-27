#ifndef SORT_METHODS_H
#define SORT_METHODS_H

void printArray(int *arr, int n);
void swap(int *arr, int a, int b);
void bubbleSort(int *vertices, int *weigth, int *connection, int n);
void selectionSort(int *vertices, int *weigth, int *connection, int n);
void insertionSort(int *vertices, int *weigth, int *connection, int n);
void partition(int *vertices, int *weigth, int *connection, int low, int high, int& i, int& j);
void quickSort(int *vertices, int *weigth, int *connection, int low, int high);
void merge(int *vertices, int *weight, int *connection, int const left, int const mid, int const right);
void mergeSort(int *vertices, int *weight, int *connection, int begin, int end);
void heapify(int *vertices, int *weigth, int *connection, int n, int i);
void heapSort(int *vertices, int *weigth, int *connection, int n);
int getMax(int * arr, int n);
void mySort(int *vertices, int *weigth, int *connection, int n);
bool conditionCheck(bool *arr, int n);
void colorCheck(int **grafo, int *vertices, int *weigth, int *connection, int n);

#endif