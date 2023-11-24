#ifndef INDREMHPP_H
#define INDREMHPP_H

#define MAX 10000

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node(string word, int pag);
    ~Node();
    string getWord();
    int getHeight();
    void setHeight(int n);
    Node* parent;
    Node* left;
    Node* right;
  private:
    string word;
    int height;
    int numpags;
    int pags[MAX];
};

#endif