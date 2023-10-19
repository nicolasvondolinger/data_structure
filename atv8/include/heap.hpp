#ifndef HEAP_HPP
#define HEAP_HPP
#include "unionFind.hpp"

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
        int* data;

        
        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
};


#endif