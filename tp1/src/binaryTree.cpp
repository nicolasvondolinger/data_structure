#include <iostream>
#include "./BinaryTree.h"

//Implementação da Árvore

void BinaryTree::Insert(Node* &p, Iten iten){
    while (p!=NULL){
        if(iten.getKey() < p->iten.getKey()){
            p = p -> left;
        } else {
            p = p -> right;
        }
    }

    p = new Node();
    p -> iten = iten;
}

void BinaryTree::Clean(){
    root = nullptr;
}
