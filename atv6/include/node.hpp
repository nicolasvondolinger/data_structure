// node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {
public:
    Node();
    void SetData(int c);
    int GetData() const;
    void SetNext(Node* node);
    Node* GetNext() const;
    std::vector<int>& GetConnections(); 
private:
    int data;
    Node* next;
    std::vector<int> connections; 
};

#endif
