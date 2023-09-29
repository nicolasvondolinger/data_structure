#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"

//Implementação da Pilha

Stack::Stack(/* args */)
{
    top = nullptr;
    length = 0;
}

Stack::~Stack()
{
    Clean();
}

void Stack::StackUp(char c){
    Node* n = new Node();

    n->SetIten(c);
    n->SetRight(top);
    top = n;
    length++;
}

char Stack::Unstack(){
    char aux; Node *p;

    if(length == 0){
        throw "The Stack is Empty!";
    }

    aux = top->GetIten();
    p = top;
    top = top->GetRight();
    delete p;
    length--;

    return aux;
}

void Stack::Clean(){
    while (!Empty()){
        Unstack();
    }
}

void Stack::SetTop(Node* node){
    top = node;
}

Node* Stack::GetTop(){
    return top;
}

char Stack::GetIten(){
    return top->GetIten();
}

int Stack::GetLength(){
    return length;
}

bool Stack::Empty(){
    return length == 0;
}
