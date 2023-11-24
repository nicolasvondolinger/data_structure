#include <iostream>

#include "avlTree.hpp"

using namespace std;

avlTree::avlTree(string word, int pag){
    root = new Node(word, pag);
}

avlTree::~avlTree(){
    
}

Node* avlTree::getRoot(){
    return root;
}

int avlTree::maxValue(int v1, int v2){
    if(v1 > v2) return v1;
    return v2;
}

int avlTree::height(Node* n){
    if(n == NULL) return -1;
    return 1 + maxValue(height(n->left), height(n->right));
}

int avlTree::balanceFactor(Node* n){
    if(n == NULL) return 0;
    int balance = n->right->height - n->left->height;
    return balance;
}

bool avlTree::contain(Node* n, string word){
    if (n == nullptr) return false;
    if (n.element == word) return true;
    if(contain(n->left, word)) return true;
    if(contain(n->right, word)) return true;
    return false;
}

Node* avlTree::rightRotate(Node* x){
    Node* y = x -> left;
    Node* z = y->right;

    y->right = x;
    x->left = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return x;
}

Node* avlTree::leftRotate(Node* x){
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* avlTree::insert(Node* n, string w, int pag){
    if(n == nullptr){
        Node* toInsert = new Node(w, pag);
        return toInsert;
    }
    if(n->getWord() > w) {
        n->right = insert(n->right, w, pag);
    }
    if(n->getWord() < w) {
        n->left = insert(n->left, w, pag);
    }
    else{
        n->pags[numpags] = pag;
        n->numpags++;
        return n;
    }
    n -> height = 1 + maxValue(height(n -> left), height(n -> right));

    int balance = balanceFactor(n);

    if(balance > 1 && w < n->left->getWord()) return rightRotate(n);
    if(balance < -1 && w > n->right->getWord()) return leftRotate(n);
    if(balance > 1 && w > n->left->getWord()){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if(balance < -1 && w < n->right->getWord()){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}