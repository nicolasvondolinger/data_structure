#include "../include/node.hpp"
#include <iostream>

using namespace std;

class ListaAdjacencia{
    public:
        ListaAdjacencia();
        ~ListaAdjacencia();
        void InsereVertice(int data);
        void InsereAresta(int v, int w);
        int QuantidadeAresta();
        int QuantidadeVertice();
    private:
        Node* head;
        int quantAresta;
        int quantVertice    
}