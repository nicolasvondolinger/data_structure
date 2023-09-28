#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

//Implementação da Pilha

stack::stack(/* args */)
{
    top.right = nullptr;
    top.left = nullptr;
    length = 0;
}

stack::~stack()
{
    Clean();
}

void StackUp(char iten){
    Node *n;

    n = new Node();
    n->iten = iten;
    n->right = top;
    top = n;
    length++;
}

char Unstack(){
    char aux; Node *p;

    if(length == 0){
        throw "The Stack is Empty!";
    }

    aux = top -> iten;
    p = top;
    top = top->right;
    delete p;
    length--;

    return aux;
}

void Clean(){
    while (!Empty()){
        Unstack();
    }
}

int Top(){
    char c = top.iten;
    return c - '0';
}

int GetLenght(){
    return length;
}

bool Empty(){
    return length == 0;
}
