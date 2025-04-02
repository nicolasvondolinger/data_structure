#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdexcept> // Incluído para lançar exceções

#include "Stack.h"

using namespace std;

// Implementação da Pilha

Stack::Stack() {
    top = nullptr;
    length = 0;
}

Stack::~Stack() {
    Clean();
}

// Empilha um caractere na pilha
void Stack::StackUp(char c) {
    Node* n = new Node();

    n->SetIten(c);
    n->SetRight(top);
    top = n;
    length++;
}

// Desempilha um caractere da pilha e retorna o caractere desempilhado
char Stack::Unstack() {
    char aux;
    Node *p;

    if (length == 0 || top == nullptr) {
        throw std::runtime_error("A pilha está vazia. Não é possível desempilhar.");
    }

    aux = top->GetIten();
    p = top;
    top = top->GetRight();
    delete p;
    length--;

    return aux;
}

// Remove todos os elementos da pilha
void Stack::Clean() {
    while (!Empty()) {
        Unstack();
    }
}

// Define o topo da pilha para um nó específico
void Stack::SetTop(Node* node) {
    top = node;
}

// Retorna o nó no topo da pilha
Node* Stack::GetTop() {
    return top;
}

// Obtém o caractere no topo da pilha
char Stack::GetIten() {
    if (top == nullptr) {
        throw std::runtime_error("A pilha está vazia. Não é possível obter um item.");
    }
    return top->GetIten();
}

// Retorna o número de elementos na pilha
int Stack::GetLength() {
    return length;
}

// Verifica se a pilha está vazia
bool Stack::Empty() {
    return length == 0;
}
