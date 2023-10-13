#pragma once
#include <string>

using namespace std;

class Node{
private:
    char iten;
    string expression;
    Node *left;
    Node *right;
public:

    Node(/* args */);
    void SetIten(char c);
    char GetIten() const;
    void SetExpression(string s);
    string GetExpression() const;
    void SetLeft(Node* node);
    Node* GetLeft() const;
    void SetRight(Node* node);
    Node* GetRight() const;
};