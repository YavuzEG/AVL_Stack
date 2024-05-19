
#include "Stack.hpp"	
	
	Stack::Stack(){
		top=nullptr;
	}
	bool Stack::isEmpty()const{
			return top	 == nullptr;
	}
	void Stack::push(const int data){
		 top= new SNode(data,top);
	}
	void Stack::pop(){
		if(isEmpty()) throw "Stack is Empty";
		SNode *tmp = top;
		top = top->next;
		delete tmp;
	}
	const int Stack::topof()const{
		if(top==nullptr) return 0;
		return top->data;
	}
	void Stack::makeEmpty(){
		while(!isEmpty()) pop();
	}
	Stack::~Stack(){
		makeEmpty();
	}