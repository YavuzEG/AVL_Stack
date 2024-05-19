
#ifndef AVL_hpp
#define AVL_hpp
#include "Node.hpp"
#include "Stack.hpp"

class AVL
{
private:
	Node* root;
	int treenum;
	Node* add(Node*, const int&);
	Node* turnright(Node*);
	Node* turnleft(Node*);
	bool del(Node*&);
	int Height(Node*);
	void pushstack(Node*,Stack&);
	int AVLToplamDugumDeger(Node*);
public:
	int gettreenum();
	int AVLToplamDugumDeger();
	AVL(int);
	Node* getroot();
	~AVL();
	bool isEmpty() const;
	void Add(const int&);
	int Height();
	void Clear();
	void pushstack(Stack&);

};
#endif