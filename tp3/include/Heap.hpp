#ifndef HEAP_HPP
#define HEAP_HPP

#include "Point.hpp"

class Heap{
    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(int x);
        int Remover();

        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        Point* data;

        /* Funções necessárias para implementar o Heapify recursivo
         * Você pode apagar elas caso decida implementar o Heapify iterativo
         */
        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
};


#endif