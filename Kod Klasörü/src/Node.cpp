
#include "Node.hpp"

Node::Node(int data)
{
    this->data = data;
    right = left = nullptr;
    height = 0;
}

Node::~Node()
{

}