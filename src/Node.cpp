#include <iostream>
#include "Node.hpp"
#include "Kisi.hpp"
#include "Stack.hpp"
#include <string>
using namespace std;

Node::Node()
{
}

Node::Node(int boy, string ad, int kilo)
{
    Node *node = new Node();
    node->kisi = new Kisi(boy, ad, kilo);
    node->DepthStack = new Stack();
    node->HeightStack = new Stack();
}