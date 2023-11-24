#include <iostream>

#include "avlTree.hpp"

using namespace std;


avlTree::avlTree(){

}

avlTree::~avlTree(){
    
}

int max::avlTree(int v1, int v2){
    if(v1 > v2) return v1;
    return v2;
}

int height::avlTree(node* n){
    if(node == NULL) return -1;
    return 1 + max(height(node->left), height(node->rigth));
}

int balanceFactor::avlTree(node* n){
    if(node == NULL) return 0;
    int balance = node->right->height - node->left->height;
    return balance;
}

bool exist::avlTree(string word){
    
}

void insert::avlTree(node* n){

}