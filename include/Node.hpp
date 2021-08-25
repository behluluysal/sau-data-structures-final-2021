#ifndef Node_hpp
#define Node_hpp

#include "Node.hpp"
#include "Kisi.hpp"
#include "Stack.hpp"
class Node
{

public:
    Node();
    Node(int yas, std::string ad, int kilo);

    Kisi* kisi;
    Stack* HeightStack;
    Stack* DepthStack;

    ~Node();
};

#endif