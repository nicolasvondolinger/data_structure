typedef class Node{
private:
    Iten iten;
    Node *left;
    Node *right;
public:
    Node(/* args */);

friend class binare_tree;
};

Node::Node(/* args */){
    iten.SetKey(-1);
    left = nullptr;
    right = nullptr;
}