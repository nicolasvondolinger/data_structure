// graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "ListaAdjacencia.hpp"

class Grafo {
public:
    Grafo();
    ~Grafo();
    void InsereVertice(int data);
    void InsereAresta(int v, int w);
    int QuantidadeVertices();
    int QuantidadeArestas();
    int GrauMinimo();
    int GrauMaximo();
    void ImprimeVizinhos();

private:
    ListaAdjacencia vertices;
};

#endif
