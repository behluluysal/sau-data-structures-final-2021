#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <iostream>
#include "AVLTree.hpp"
#include "Node.hpp"
#include "Stack.hpp"
using namespace std;
class AVLTree
{

public:
    AVLTree();
    AVLTree(int, string, int);

    Node *node;
    AVLTree *left;
    AVLTree *right;
    int height;

    int max(int a, int b);
    int getHeight(AVLTree *N);
    AVLTree *newNode(int yas, string ad, int kilo);
    AVLTree *rightRotate(AVLTree *y);
    AVLTree *leftRotate(AVLTree *x);
    int getBalance(AVLTree *N);
    AVLTree *insert(AVLTree *node, int key, string ad, int tarih);
    void Postorder(AVLTree *root);

    ~AVLTree();
};

#endif