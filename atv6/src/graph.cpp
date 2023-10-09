// graph.cpp
#include "graph.hpp"

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice(int data) {
    vertices.InsereVertice(data);
}

void Grafo::InsereAresta(int v, int w) {
    vertices.InsereAresta(v, w);
}

int Grafo::QuantidadeVertices() {
    return vertices.QuantidadeVertice();
}

int Grafo::QuantidadeArestas() {
    return vertices.QuantidadeAresta();
}

int Grafo::GrauMinimo() {
    return vertices.GrauMinimo();
}

int Grafo::GrauMaximo() {
    return vertices.GrauMaximo();
}

void Grafo::ImprimeVizinhos() {
    vertices.ImprimeVizinhos();
}
