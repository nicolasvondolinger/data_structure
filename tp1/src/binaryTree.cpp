#include <iostream>
#include "./BinaryTree.h"

//Implementação da Árvore

BinaryTree::BinaryTree(){
    root = nullptr;
}

BinaryTree::~BinaryTree(){
    Erase(GetRoot());
}

void BinaryTree::Erase(Node* p) {
    if (p != nullptr) {
        Erase(p->GetLeft());  
        Erase(p->GetRight());  
        delete p;              
    }
}

Node* BinaryTree::GetRoot(){
    return root;
}

void BinaryTree::SetRoot(string s){
    if (root == nullptr) {
        root = new Node();
    }
    root->SetExpression(s);
}

void BinaryTree::InsertLeft(Node* node, string exp) {
    if (node == nullptr) {
        return; // Se o nó for nulo, não podemos inserir à esquerda.
    }
        Node* newNode = new Node();
        newNode->SetExpression(exp);
        node->SetLeft(newNode);
}

void BinaryTree::InsertRight(Node* node, string exp) {
    if (node == nullptr) {
        return; // Se o nó for nulo, não podemos inserir à esquerda.
    }
        Node* newNode = new Node();
        newNode->SetExpression(exp);
        node->SetRight(newNode);
}

void BinaryTree::PreOrder(Node* p) {
    if (p != nullptr) {
        cout << p->GetIten() << " ";
        PreOrder(p->GetLeft());
        PreOrder(p->GetRight());
    }
}

void BinaryTree::InOrder(Node* p) {
    if (p != nullptr) {
        InOrder(p->GetLeft());
        cout << p->GetIten() << " ";
        InOrder(p->GetRight());
    }
}

void BinaryTree::PosOrder(Node* p) {
    if (p != nullptr) {
        PosOrder(p->GetLeft());
        PosOrder(p->GetRight());
        cout << p->GetIten() << " ";
    }
}