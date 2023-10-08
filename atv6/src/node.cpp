#include "../include/node.hpp"

Node::Node(){
    next = nullptr;
}

void Node::SetIten(int c){
    iten = c;
}

int Node::GetIten() const {
    return iten;
}

void Node::SetNext(Node* node){
    next = node;
}

Node* Node::GetNext() const {
    return next;
}