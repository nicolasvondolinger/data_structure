#include <iostream>
#include "./BinareTree.h"

//Implementação da Árvore

void BinareTree::Insert(Node* &p, Iten iten){
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

void BinareTree::Clean(){
    root = nullptr;
}
