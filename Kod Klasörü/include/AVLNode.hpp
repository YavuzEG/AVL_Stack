
#ifndef AVLNode_hpp
#define AVLNode_hpp
#include "AVL.hpp"
#include "Stack.hpp"

class Cnode
{
public:
	Cnode(AVL*);
	~Cnode();
	AVL* avl;
	Cnode* cnext;
	Stack* stack;
	
};


#endif