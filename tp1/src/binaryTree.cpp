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
    root->SetExpression(s);
}

void BinaryTree::InsertLeft(Node* node, string exp) {
    if (node == nullptr) {
        return; 
    }

    if (node->GetLeft() == nullptr) {
        Node* newNode = new Node();
        newNode->SetExpression(exp);
        node->SetLeft(newNode);
    } else {
        InsertLeft(node->GetLeft(), exp);
    }
}

void BinaryTree::InsertRight(Node* node, string exp) {
    if (root == nullptr) {
        root = new Node();
        root->SetExpression(exp);
    } else {
        Node* newNode = new Node();
        newNode->SetExpression(exp);
        newNode->SetRight(root->GetRight());
        root->SetRight(newNode);
    }
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