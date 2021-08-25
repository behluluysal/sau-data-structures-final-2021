// veri_part1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "Stack.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> split(string target, string delim);

int main()
{
    std::cout << "Hello World!\n";
    AVLTree* root = NULL;
    root = root->insert(root, 30, "rihanna", 45);
    root->Postorder(root,root);
    root = root->insert(root, 32, "Elliana", 38);
    root->Postorder(root,root);
    root = root->insert(root, 36, "Savannah", 22);
    root->Postorder(root,root);
    root = root->insert(root, 25, "Savannah", 22);
    root->Postorder(root, root);
    root = root->insert(root, 22, "Savannah", 22);
    root->Postorder(root, root);
    root = root->insert(root, 16, "Savannah", 22);
    root->Postorder(root, root);
    root = root->insert(root, 26, "Savannah", 22);
    root->Postorder(root, root);
    root = root->insert(root, 27, "Savannah", 22);
    root->Postorder(root, root);
    if (root->isBalanced(root))
        std::cout << "Tree is balanced\n";
    else
        std::cout << "Tree is not balanced";
    root->printLevelOrder(root);


}


vector<string> split(string target, string delim)
{
    vector<string> v;
    if (!target.empty())
    {
        string::size_type start = 0;
        do
        {
            size_t x = target.find(delim, start);
            if (x == string::npos)
                break;

            v.push_back(target.substr(start, x - start));
            start = x + delim.size();
        } while (true);

        v.push_back(target.substr(start));
    }
    return v;
}
