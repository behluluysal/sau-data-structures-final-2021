#include "Node.hpp"

Node::Node()
{
    this->kisi = NULL;
    this->DepthStack = NULL;
    this->HeightStack = NULL;
}

Node::Node(int boy, string ad, int yas)
{
    this->kisi = new Kisi(boy, ad, yas);
    this->DepthStack = new Stack();
    this->HeightStack = new Stack();
}

Node::~Node(){
    
}