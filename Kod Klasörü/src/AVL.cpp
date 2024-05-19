
#include "AVL.hpp"
#include <iostream>
#include <cmath>

using namespace std;
	Node* root;

	Node* AVL::add(Node* subNode, const int& item) {
		if (subNode == nullptr) subNode = new Node(item);
		else if (item < subNode->data) {
			subNode->left = add(subNode->left, item);

			if (Height(subNode->left) == Height(subNode->right) + 2) {
				if (item < subNode->left->data)
					subNode = turnright(subNode);
				else {
					subNode->left = turnleft(subNode->left);
					subNode = turnright(subNode);
				}
			}
		}
		else if (item > subNode->data) {
			subNode->right = add(subNode->right, item);

			if (Height(subNode->right) == Height(subNode->left) + 2) {
				if (item > subNode->right->data)
					subNode = turnleft(subNode);
				else {
					subNode->right = turnright(subNode->right);
					subNode = turnleft(subNode);
				}
			}
		}
		else;

		subNode->height = Height(subNode);
		return subNode;
	}
	Node* AVL::turnright(Node* subNode) {
		Node* tmp = subNode->left;
		subNode->left = tmp->right;
		tmp->right = subNode;

		subNode->height = Height(subNode);
		tmp->height = 1 +max(Height(tmp->left), subNode->height);

		return tmp;
	}
	Node* AVL::turnleft(Node* subNode) {
		Node* tmp = subNode->right;
		subNode->right = tmp->left;
		tmp->left = subNode;

		subNode->height = Height(subNode);
		tmp->height = 1 + max(Height(tmp->right), subNode->height);

		return tmp;
	}
	bool AVL::del(Node*& subNode) {
		Node* delNode = subNode;

		if (subNode->right == nullptr) subNode = subNode->left;
		else if (subNode->left == nullptr) subNode = subNode->right;
		else {
			delNode = subNode->left;
			Node* parentNode = subNode;
			while (delNode->right != nullptr) {
				parentNode = delNode;
				delNode = delNode->right;
			}
			subNode->data = delNode->data;
			if (parentNode == subNode) subNode->left = delNode->left;
			else parentNode->right = delNode->left;
		}
		delete delNode;
		return true;
	}

	Node* AVL::getroot()
	{
		return root;
	}

	int AVL::Height(Node* subNode) {
		if (subNode == NULL) return -1;
		return 1 + max(Height(subNode->left), Height(subNode->right));
	}

	AVL::AVL(int num) {
		root = nullptr;
		this->treenum=num;
	}
	bool AVL::isEmpty()const {
		return root == nullptr;
	}
	void AVL::Add(const int& item) {
		root = add(root, item);
	}

	int AVL::Height() {
		return Height(root);
	}
	
	void AVL::Clear() {
		while (!isEmpty()) del(root);
	}
	AVL::~AVL() {
		Clear();
	}


	void AVL::pushstack(Node* current,Stack& leaf)
	{
		if(current==nullptr) return;
		
		
		pushstack(current->left,leaf);
		pushstack(current->right,leaf);

			if(!current->left && !current->right)
			{
				leaf.push(current->data);
			}
		
	}

	void AVL::pushstack(Stack& leaf)
	{
		pushstack(root,leaf);
	}


int AVL::AVLToplamDugumDeger(Node* current)
{
	if(current==nullptr || (current->left==nullptr && current->right==nullptr))
		return 0;
	
	int toplam=current->data;
	toplam+=AVLToplamDugumDeger(current->left);
	toplam+=AVLToplamDugumDeger(current->right);
	return toplam;
}
	
int  AVL::AVLToplamDugumDeger()
{
	return AVLToplamDugumDeger(root);
}

int AVL::gettreenum()
{
	return treenum;
}