#include <iostream>
#include "heap.hpp"

using namespace std;

Heap::Heap(int maxsize){
    data = new int[maxsize];
    tamanho = 0;
}

Heap::~Heap(){
    delete[] data;
}

void Heap::Inserir(int x) {
    data[tamanho] = x;
    int posicao = tamanho;
    int pai = GetAncestral(posicao);
    while (posicao > 0 && data[posicao] < data[pai]) {
        int aux = data[posicao];
        data[posicao] = data[pai];
        data[pai] = aux;
        posicao = pai;
        pai = GetAncestral(posicao);
    }
    tamanho++;
}


int Heap::Remover() {
    int root = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    int i = 0;
    while (true) {
        int esq = GetSucessorEsq(i);
        int dir = GetSucessorDir(i);
        int menor = i;

        if (esq < tamanho && data[esq] < data[menor]) {
            menor = esq;
        }
        if (dir < tamanho && data[dir] < data[menor]) {
            menor = dir;
        }

        if (menor == i) {
            break; // O elemento atual é menor que os filhos, portanto, a propriedade da Min Heap está preservada.
        }

        // Trocar o elemento atual com o menor dos filhos.
        int aux = data[i];
        data[i] = data[menor];
        data[menor] = aux;

        i = menor;
    }

    return root;
}


bool Heap::Vazio(){
    return tamanho == 0;
}

int Heap::GetAncestral(int posicao){
    return (posicao-1)/2;
}

int Heap::GetSucessorEsq(int posicao){
    return 2 * posicao + 1;
}

int Heap::GetSucessorDir(int posicao){
    return 2 * posicao + 2;
}

void Heap::HeapifyPorBaixo(int posicao){
}

void Heap::HeapifyPorCima(int posicao){

}