#include "Node.h"

class BinaryTree{
private:
    Node *root;
public:
    BinaryTree();
    ~BinaryTree();
    
    void InsertRight(Node* node, string exp);
    void InsertLeft(Node* node, string exp);
    void Erase(Node* p);
    Node* GetRoot();
    void SetRoot(string exp);
    void ByLevel();
    void PreOrder(Node* p);
    void InOrder(Node* p);
    void PosOrder(Node* p);
    
};

