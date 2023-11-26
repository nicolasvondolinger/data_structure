#ifndef INDREMHPP_H
#define INDREMHPP_H

#define MAX 10000000

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node* left;
    Node* right;
    string word;
    int height;
    int numpags;
    int pags[MAX];
  private:
};

#endif