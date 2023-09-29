#pragma once

class Node{
private:
    char iten;
    Node *left;
    Node *right;
public:
    Node(/* args */);
    void SetIten(char c);
    char GetIten() const;
    void SetLeft(Node* node);
    Node* GetLeft() const;
    void SetRight(Node* node);
    Node* GetRight() const;
};