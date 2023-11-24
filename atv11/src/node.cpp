#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

Node::Node(string word, int pag)[
    parent = nullptr;
    right = nullptr;
    left = nullptr;
    height = 0;
    numpags = 1;
    pags[0] = pag;
]

Node::~Node(){
    
}