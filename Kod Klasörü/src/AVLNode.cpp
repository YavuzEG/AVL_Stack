
#include "AVLNode.hpp"

Cnode::Cnode(AVL* avl)
{
	this->avl = avl;
	cnext = 0;
	stack=new Stack();
}

Cnode::~Cnode()
{
	delete stack;
}