#ifndef Node_hpp
#define Node_hpp
#include <iostream>
#include "Node.hpp"
#include "Kisi.hpp"
#include "Stack.hpp"

#include <string>
using namespace std;
class Node
{

public:
    Node();
    Node(int, string, int);

    Kisi *kisi;
    Stack *HeightStack;
    Stack *DepthStack;
    int height;
    int age;

    int max(int a, int b);
    int getHeight(Node *N);
    Node *newNode(int yas, string ad, int kilo);
    void PushHeight(Node *root, int Height);
    void PushDepth(Node * root, int Depth);

    ~Node();
};

#endif