#include "node.h"

typedef class stack{
private:
    /* data */
    int length;
    Node* top;
public:
    //Constructors
    stack();
    ~stack();

    void StackUp(char iten);
    char Unstack();
    void Clean();
    int Top();

    int GetLength();
    bool Empty();
};


