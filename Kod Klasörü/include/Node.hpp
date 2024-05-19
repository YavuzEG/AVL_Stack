
#ifndef Node_hpp
#define Node_hpp

class Node
{
public:
    int data;
    Node* right;
    Node* left;
    int height;
    Node(int);
    ~Node();
};

#endif

