#include "AVLTree.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>


AVLTree::AVLTree()
{
    this->height = 0;
    this->left = NULL;
    this->right = NULL;
    this->node = NULL;
}


AVLTree* AVLTree::newNode(int yas, string ad, int boy)
{
    AVLTree* agac = new AVLTree();
    agac->node = new Node(yas, ad, boy);
    agac->left = NULL;
    agac->right = NULL;
    agac->height = 1; // new node is initially
                      // added at leaf
    return (agac);
}



AVLTree* AVLTree::rightRotate(AVLTree* y)
{
    AVLTree* x = y->left;
    AVLTree* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left),
        getHeight(y->right))+1;
    x->height = max(getHeight(x->left),
        getHeight(x->right))+1;

    // Return new root
    return x;
}

AVLTree* AVLTree::leftRotate(AVLTree* x)
{
    AVLTree* y = x->right;
    AVLTree* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left),
        getHeight(x->right))+1;
    y->height = max(getHeight(y->left),
        getHeight(y->right)) +
        1;

    // Return new root
    return y;
}

int AVLTree::getBalance(AVLTree* N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

AVLTree* AVLTree::insert(AVLTree* agac, int key, string ad, int yas)
{
    //key = boy
    /* 1. Perform the normal BST insertion */
    if (agac == NULL)
        return (newNode(key, ad, yas));

    //küçük eşit ise sol ekle
    if (key <= agac->node->kisi->height)
        agac->left = insert(agac->left, key, ad, yas);
    else if (key > agac->node->kisi->height)
        agac->right = insert(agac->right, key, ad, yas);

    /* 2. Update height of this ancestor node */
    agac->height = 1+max(getHeight(agac->left),
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
bool AVLTree::isBalanced(AVLTree* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = getHeight(root->left);
    rh = getHeight(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    /* If we reach here then
    tree is not height-balanced */
    return 0;
}

void AVLTree::Postorder(AVLTree* root, AVLTree *tail)
{
    if (tail == NULL)
        return;

    // first recur on left subtree
    Postorder(root, tail->left);

    // then recur on right subtree
    Postorder(root, tail->right);

    // now deal with the node
    
    tail->node->DepthStack->push('0'+findDepth(root, tail->node->kisi->height));
    tail->node->HeightStack->push('0' + tail->height);
}

int AVLTree::getHeight(AVLTree* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int AVLTree::max(int a, int b)
{
    return (a > b) ? a : b;
}

int AVLTree::findDepth(AVLTree* root, int x)
{
    // Base case
    if (root == NULL)
        return -1;

    // Initialize distance as -1
    int dist = -1;

    // Check if x is current node=
    if ((root->node->kisi->height == x)

        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0

        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)

        // Return depth of the node
        return dist + 1;

    return dist;
}

int AVLTree::FindMaxHeight(AVLTree* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = FindMaxHeight(node->left);
        int rheight = FindMaxHeight(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
            return(rheight + 1);
        }
    }
}


/* Function to print level
order traversal a tree*/
void AVLTree::printLevelOrder(AVLTree* root)
{
    int h = FindMaxHeight(root);
    int i;
    std::cout << "Level Order: \n";
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
    }
}

/* Print nodes at a current level */
void AVLTree::printCurrentLevel(AVLTree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        std::cout << root->node->kisi->ad <<" "<< root->node->kisi->height << " ";
        //Print Height Stack
        std::cout << "Y(";
        int a;
        while (root->node->HeightStack->top != -1)
        {
            a = root->node->HeightStack->pop()-'0'-1;
            std::cout << a;
            if (root->node->HeightStack->top != -1)
                std::cout << ",";
        }
        std::cout << ")";
        //Print Depth Stack
        std::cout << "D";
        root->node->DepthStack->print();
    } 
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

AVLTree::~AVLTree()
{
}
