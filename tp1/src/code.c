#include <stdlib.h>
#include <stdio.h>

#include "binare_tree.h"

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