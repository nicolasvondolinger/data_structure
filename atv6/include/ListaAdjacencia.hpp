#include "node.hpp"

class ListaAdjacencia{
    public:
        ListaAdjacencia();
        ~ListaAdjacencia();
        Node* Begin();
        Node* End();
        void InsereVertice();
        void InsereAresta();
        int QuantidadeVertice();
        int QuantidadeAresta();
        
    private:
        int quantVertice;
        int quantAresta;
};

