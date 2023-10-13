#include "Node.h"
#include <string>

Node::Node(){
    left = nullptr;
    right = nullptr;
}

void Node::SetIten(char c){
    iten = c;
}

char Node::GetIten() const {
    return iten;
}

void Node::SetExpression(string s){
    expression = s;
}

string Node::GetExpression() const{
    return expression;
}

void Node::SetRight(Node* node){
    right = node;
}

Node* Node::GetRight() const {
    return right;
}

void Node::SetLeft(Node* node){
    left = node;
}

Node* Node::GetLeft() const {
    return left;
}