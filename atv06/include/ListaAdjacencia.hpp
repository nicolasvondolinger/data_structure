// ListaAdjacencia.hpp
#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "node.hpp"

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia(); // Adicione o destrutor
    void InsereVertice(int data);
    void InsereAresta(int v, int w);
    int QuantidadeAresta();
    int QuantidadeVertice();
    int GrauMinimo();
    int GrauMaximo();
    void ImprimeVizinhos();

private:
    Node* head;
    int quantAresta;
    int quantVertice;
};

#endif
