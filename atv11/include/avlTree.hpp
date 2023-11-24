#include <iostream>
#include "node.hpp"

using namespace std;

class avlTree{
    public:
        avlTree(string word, int pag);
        ~avlTree();
        Node* getRoot();
        int height(Node* n);
        int maxValue(int v1, int v2);
        int balanceFactor(Node* n);
        bool contain(Node* n, string word);
        Node* rightRotate(Node* x);
        Node* leftRotate(Node* y);
        Node* insert(Node* n,string w, int pag);
    private:
        Node* root;
};
