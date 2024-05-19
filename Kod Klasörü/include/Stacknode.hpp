
#ifndef Stacknode_hpp
#define Stacknode_hpp

class SNode
{
    public:
    SNode(int,SNode*);
    int data;
    SNode* next;
};

#endif