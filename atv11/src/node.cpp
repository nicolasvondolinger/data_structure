#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

Node::Node(string w, int pag){
    parent = nullptr;
    right = nullptr;
    left = nullptr;
    height = 0;
    numpags = 1;
    word = w;
    pags[0] = pag;
}

Node::~Node(){
    
}

string Node::getWord(){
    return word;
}

int Node::getHeight(){
    return height;
}

void Node::setHeight(int n){
    height = n;
}