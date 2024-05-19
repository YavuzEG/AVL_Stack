
#ifndef Stack_hpp
#define Stack_hpp
#include "Stacknode.hpp"

class Stack
{
	public:
	Stack();	
	~Stack();
	bool isEmpty()const;
	void push(const int );
	void pop();
	const int topof()const;
	void makeEmpty();

	private:
	SNode* top;


};

#endif