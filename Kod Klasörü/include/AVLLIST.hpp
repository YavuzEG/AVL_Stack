
#ifndef AVLLIST_hpp
#define AVLLIST_hpp
#include "AVLNode.hpp"
#include "AVL.hpp"

class Control
{
public:
	Control();
	~Control();
	void addtree(AVL*);
	Cnode* cfirst;
	int avlsayi=0;
	void pushstacks();
	void deletestacks();
	void lastfunc();

};
#endif