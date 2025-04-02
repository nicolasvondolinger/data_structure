#include "Node.h"
#include <stdexcept> // Incluído para lançar exceções

Node::Node() {
    left = nullptr;
    right = nullptr;
}

// Define o caractere associado a este nó
void Node::SetIten(char c) {
    iten = c;
}

// Retorna o caractere associado a este nó
char Node::GetIten() const {
    return iten;
}

// Define a expressão associada a este nó
void Node::SetExpression(string s) {
    expression = s;
}

// Retorna a expressão associada a este nó
string Node::GetExpression() const {
    return expression;
}

// Define o nó à direita deste nó
void Node::SetRight(Node* node) {
    if (this->right != nullptr) {
        throw std::runtime_error("O nó já tem um filho direito. Não é possível definir um novo filho direito.");
    }
    right = node;
}

// Retorna o nó à direita deste nó
Node* Node::GetRight() const {
    return right;
}

// Define o nó à esquerda deste nó
void Node::SetLeft(Node* node) {
    if (this->left != nullptr) {
        throw std::runtime_error("O nó já tem um filho esquerdo. Não é possível definir um novo filho esquerdo.");
    }
    left = node;
}

// Retorna o nó à esquerda deste nó
Node* Node::GetLeft() const {
    return left;
}
