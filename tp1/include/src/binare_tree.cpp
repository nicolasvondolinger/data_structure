#include <iostream>
#include "./binare_tree.h"

//Implementação da Árvore

void Insert(Node* &p, Iten iten){
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

void Clean(){
    
    root = nullptr;
}