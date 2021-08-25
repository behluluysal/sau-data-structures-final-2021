#include <iostream>
#include "AVLTree.hpp"
#include "Node.hpp"
#include <string>

using namespace std;

AVLTree::AVLTree()
{
}


AVLTree::AVLTree(int boy, string ad, int kilo)
{
    //node kurucusunu çağır
    node = new Node(boy,ad,kilo);
}

AVLTree *AVLTree::newNode(int boy, string ad, int kilo)
{
    AVLTree *agac = new AVLTree(boy, ad, kilo);
    agac->left = NULL;
    agac->right = NULL;
    agac->height = 1; // new node is initially
                      // added at leaf
    return (agac);
}

AVLTree *AVLTree::rightRotate(AVLTree *y)
{
    AVLTree *x = y->left;
    AVLTree *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left),
                    getHeight(y->right)) +
                1;
    x->height = max(getHeight(x->left),
                    getHeight(x->right)) +
                1;

    // Return new root
    return x;
}

AVLTree *AVLTree::leftRotate(AVLTree *x)
{
    AVLTree *y = x->right;
    AVLTree *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left),
                    getHeight(x->right)) +
                1;
    y->height = max(getHeight(y->left),
                    getHeight(y->right)) +
                1;

    // Return new root
    return y;
}

int AVLTree::getBalance(AVLTree *N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

AVLTree *AVLTree::insert(AVLTree *agac, int key, string ad, int kilo)
{
    /* 1. Perform the normal BST insertion */
    if (agac == NULL)
        return (newNode(key, ad, kilo));

    if (key <= agac->node->kisi->height)
        agac->left = insert(agac->left, key, ad, kilo);
    else if (key > agac->node->kisi->height)
        agac->right = insert(agac->right, key, ad, kilo);

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(getHeight(agac->left),
                           getHeight(agac->right));

    /* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
    int balance = getBalance(agac);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < agac->left->node->kisi->height)
        return rightRotate(agac);

    // Right Right Case
    if (balance < -1 && key > agac->right->node->kisi->height)
        return leftRotate(agac);

    // Left Right Case
    if (balance > 1 && key > agac->left->node->kisi->height)
    {
        agac->left = leftRotate(agac->left);
        return rightRotate(agac);
    }

    // Right Left Case
    if (balance < -1 && key < agac->right->node->kisi->height)
    {
        agac->right = rightRotate(agac->right);
        return leftRotate(agac);
    }

    /* return the (unchanged) node pointer */
    return agac;
}

void AVLTree::Postorder(AVLTree *root)
{
    if (root == NULL)
        return;

    // first recur on left subtree
    Postorder(root->left);

    // then recur on right subtree
    Postorder(root->right);

    // now deal with the node
    cout << root->node->kisi->ad << ", " << 2020 - root->node->kisi->height << ", " << root->node->kisi->weight << "  Yigit: ";
    while (root->node->HeightStack->top != -1)
    {
        char a;
        a = root->node->HeightStack->pop();
        cout << a << " ";
    }
    cout << endl;
    delete (root->node->HeightStack);
    delete (root->node->kisi);
    if (root->left != NULL)
    {
        delete (root->left);
        root->left = NULL;
    }

    if (root->right != NULL)
    {
        delete (root->right);
        root->right = NULL;
    }
}

int AVLTree::getHeight(AVLTree *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int AVLTree::max(int a, int b)
{
    return (a > b) ? a : b;
}



AVLTree::~AVLTree()
{
}
