#pragma once

class Node{
private:
    int conections[10000];
    Node *next;
public:
    Node(/* args */);
    void SetIten(int c);
    int GetIten() const;
    void SetNext(Node* node);
    Node* GetNext() const;
};