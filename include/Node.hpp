#ifndef Node_hpp
#define Node_hpp

#include "Node.hpp"
#include "Kisi.hpp"
#include "Stack.hpp"

#include <iostream>
#include <string>
class Node
{

public:
public:
    Node();
    Node(int yas, string ad, int kilo);

    Kisi* kisi;
    Stack* HeightStack;
    Stack* DepthStack;

    ~Node();
};

#endif