#include "./BinaryTree.h"
#include <iostream>
#include <stdexcept> // Incluído para lançar exceções

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    Erase(GetRoot());
}

// Remove todos os nós da árvore começando pela raiz
void BinaryTree::Erase(Node* p) {
    if (p != nullptr) {
        Erase(p->GetLeft());
        Erase(p->GetRight());
        delete p;
    }
}

// // Retorna o nó raiz da árvore
Node* BinaryTree::GetRoot() {
    return root;
}

// Define a raiz da árvore com a expressão fornecida
void BinaryTree::SetRoot(string s) {
    if (root != nullptr) {
        throw std::runtime_error("A raiz já está definida. Não é possível definir uma nova raiz.");
    }
    root = new Node();
    root->SetExpression(s);
}

// Insere um nó à esquerda do nó fornecido com a expressão fornecida
void BinaryTree::InsertLeft(Node* node, string exp) {
    if (node == nullptr) {
        throw std::invalid_argument("O nó fornecido é nulo. Não é possível inserir à esquerda.");
    }
    Node* newNode = new Node();
    newNode->SetExpression(exp);
    node->SetLeft(newNode);
}

// Insere um nó à direita do nó fornecido com a expressão fornecida
void BinaryTree::InsertRight(Node* node, string exp) {
    if (node == nullptr) {
        throw std::invalid_argument("O nó fornecido é nulo. Não é possível inserir à direita.");
    }
    Node* newNode = new Node();
    newNode->SetExpression(exp);
    node->SetRight(newNode);
}

// Realiza uma travessia em pré-ordem da árvore, imprimindo os nós
void BinaryTree::PreOrder(Node* p) {
    if (p != nullptr) {
        cout << p->GetIten() << " ";
        PreOrder(p->GetLeft());
        PreOrder(p->GetRight());
    }
}

// Realiza uma travessia em ordem da árvore, imprimindo os nós
void BinaryTree::InOrder(Node* p) {
    if (p != nullptr) {
        InOrder(p->GetLeft());
        cout << p->GetIten() << " ";
        InOrder(p->GetRight());
    }
}

// Realiza uma travessia em pós-ordem da árvore, imprimindo os nós
void BinaryTree::PosOrder(Node* p) {
    if (p != nullptr) {
        PosOrder(p->GetLeft());
        PosOrder(p->GetRight());
        cout << p->GetIten() << " ";
    }
}