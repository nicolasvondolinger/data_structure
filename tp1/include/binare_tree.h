
#include "node.h"

typedef class binare_tree{
private:
    void Insert();
    void Erase();
    void ByLevel();
    void PreOrder(Node* p);
    void InOrder(Node* p);
    void PosOrder(Node* p);

    Node *root;

public:
    binare_tree();
    ~binare_tree();

    void Insert(Iten i);
    void Walk(int t);
    void Clean();
};

binare_tree::binare_tree(){
    root = nullptr;
}

binare_tree::~binare_tree(){
    Clean();
}
