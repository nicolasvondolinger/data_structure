#include "../include/node.hpp"

Node::Node() : data(-1), next(nullptr) {}

void Node::SetData(int c) {
    data = c;
}

int Node::GetData() const {
    return data;
}

void Node::SetNext(Node* node) {
    next = node;
}

Node* Node::GetNext() const {
    return next;
}

int* Node::GetConnections() {
    return connections;
}