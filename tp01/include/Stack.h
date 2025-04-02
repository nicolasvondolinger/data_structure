#include "Node.h"

class Stack{
private:
    /* data */
    int length;
    Node* top;
public:
    //Constructors
    Stack();
    ~Stack();

    void StackUp(char iten);
    char Unstack();
    void Clean();

    Node* GetTop();
    void SetTop(Node* node);
    
    char GetIten();

    int GetLength();
    bool Empty();
};


