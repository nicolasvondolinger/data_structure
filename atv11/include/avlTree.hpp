#include <iostream>
#include "node.hpp"

using namespace std;

class avlTree{
    public:
        avlTree(/* args */);
        ~avlTree();
        int height(node* n);
        int max(int v1, int v2);
        int balanceFactor(node* n);
    private:

};
