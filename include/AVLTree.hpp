#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <iostream>
#include "AVLTree.hpp"
#include "Node.hpp"

class AVLTree
{

public:
AVLTree();

    Node* node;
    AVLTree* left;
    AVLTree* right;
    int height;

    int max(int a, int b);
    int getHeight(AVLTree* N);
    AVLTree* newNode(int yas, std::string ad, int boy);
    int findDepth(AVLTree* root, int x);

    int FindMaxHeight(AVLTree* node);
    void printLevelOrder(AVLTree* root);
    void printCurrentLevel(AVLTree* root, int level);

    AVLTree* rightRotate(AVLTree* y);
    AVLTree* leftRotate(AVLTree* x);
    int getBalance(AVLTree* N);

    AVLTree* insert(AVLTree* node, int key, std::string ad, int tarih);
    void UpdateTree(AVLTree* root, AVLTree* tail);
    bool isBalanced(AVLTree* root);

    void GarbageCollector(AVLTree *root);
    ~AVLTree();
};

#endif