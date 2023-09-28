#include "Node.h"

typedef class Stack{
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

    char Top();

    int GetLength();
    bool Empty();
};


