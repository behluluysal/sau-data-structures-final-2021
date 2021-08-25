// veri_part1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "Stack.hpp"
#include "AVLTree.hpp"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::string> split(std::string target, std::string delim);
AVLTree *addNewNode(AVLTree* root, std::vector<std::string> vek);

int main()
{
    AVLTree *root = NULL;
    std::vector<std::string> v;
    std::ifstream file("Kisiler.txt");

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            v = split(line, "#");   
            root = addNewNode(root,v);
        }
        file.close();
    }

    if (root->isBalanced(root))
        std::cout << "\n\nTree is balanced\n\n";
    else
        std::cout << "\n\nTree is not balanced\n\n";
    root->printLevelOrder(root);
    root->GarbageCollector(root);

    std::cout<<"\n\n\nPress any key to close the program...";
    std::getchar();
    return 0;
}
AVLTree *addNewNode(AVLTree* root, std::vector<std::string> vek)
{
    std::stringstream geek(vek[1]);
    std::stringstream geek2(vek[2]);
    int boy = 0;
    int yas = 0;
    geek >> yas;
    geek2 >> boy;
    root = root->insert(root,boy,vek[0],yas);
    root->UpdateTree(root,root);
    return root;
}


std::vector<std::string> split(std::string target, std::string delim)
{
    std::vector<std::string> v;
    if (!target.empty())
    {
        std::string::size_type start = 0;
        do
        {
            size_t x = target.find(delim, start);
            if (x == std::string::npos)
                break;

            v.push_back(target.substr(start, x - start));
            start = x + delim.size();
        } while (true);

        v.push_back(target.substr(start));
    }
    return v;
}
