#ifndef INDREMHPP_H
#define INDREMHPP_H

#define MAX 1e6

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node* parent;
    Node* left;
    Node* rigth;
  private:
    string word;
    int height;
    int numpags;
    int pags[MAX];
};

class IndRem {
  public:
    Dupla indice[MAXINDICE];
    int numpalavras;
};

#endif