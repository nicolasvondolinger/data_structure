#include "../include/listaAdjacencia.hpp"
#include <iostream>

using namespace std;

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