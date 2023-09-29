#include "Node.h"

class BinaryTree{
private:
    void Insert();
    void Erase();
    void ByLevel();
    void PreOrder(Node* p);
    void InOrder(Node* p);
    void PosOrder(Node* p);

    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    
    
    void Insert(char i);
    void Walk(int t);
    void Clean();
};

BinaryTree::BinaryTree(){
    root = nullptr;
}

BinaryTree::~BinaryTree(){
    Clean();
}
