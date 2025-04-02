// ListaAdjacencia.cpp
#include "ListaAdjacencia.hpp"
#include <iostream>
#include <limits>

ListaAdjacencia::ListaAdjacencia() : head(nullptr), quantAresta(0), quantVertice(0) {}

ListaAdjacencia::~ListaAdjacencia() {
    while (head != nullptr) {
        Node* toRemove = head;
        head = head->GetNext();
        delete toRemove;
    }
}

void ListaAdjacencia::InsereVertice(int data) {
    Node* newNode = new Node();
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->GetNext() != nullptr) {
            current = current->GetNext();
        }
        current->SetNext(newNode);
    }
    newNode->SetData(data);
    quantVertice++;
}

void ListaAdjacencia::InsereAresta(int v, int w) {
    Node* nodeV = head;
    
    while(true){
        if (nodeV->GetData() == v){
            nodeV->GetConnections().push_back(w);
            break;
        }
        nodeV = nodeV->GetNext();
    }
    
    quantAresta++;
}

int ListaAdjacencia::QuantidadeAresta() {
    return quantAresta/2;
}

int ListaAdjacencia::QuantidadeVertice() {
    return quantVertice;
}

int ListaAdjacencia::GrauMinimo() {
    int min = std::numeric_limits<int>::max();

    for (Node* current = head; current != nullptr; current = current->GetNext()) {
        int degree = current->GetConnections().size();
        if (degree < min) {
            min = degree;
        }
    }

    return min;
}

int ListaAdjacencia::GrauMaximo() {
    int max = 0;
    
    for (Node* current = head; current != nullptr; current = current->GetNext()) {
        int degree = current->GetConnections().size();
        if (degree > max) {
            max = degree;
        }
    }
    
    return max;
}

void ListaAdjacencia::ImprimeVizinhos() {
    for (Node* current = head; current != nullptr; current = current->GetNext()) {
        for (int neighbor : current->GetConnections()) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
