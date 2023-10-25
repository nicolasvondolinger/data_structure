#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    Node();
    void SetData(int c);
    int GetData() const;
    void SetNext(Node* node);
    Node* GetNext() const;
    int* GetConnections(); 
private:
    int data;
    Node* next;
    int* connections; 
};

#endif