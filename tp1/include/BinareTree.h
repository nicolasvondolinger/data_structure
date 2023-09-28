
#include "Node.h"

typedef class BinareTree{
private:
    void Insert();
    void Erase();
    void ByLevel();
    void PreOrder(Node* p);
    void InOrder(Node* p);
    void PosOrder(Node* p);

    Node *root;

public:
    BinareTree();
    ~BinareTree();

    void Insert(Iten i);
    void Walk(int t);
    void Clean();
};

BinareTree::BinareTree(){
    root = nullptr;
}

BinareTree::~BinareTree(){
    Clean();
}
