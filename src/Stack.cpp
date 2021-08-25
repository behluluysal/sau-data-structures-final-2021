#include "Stack.hpp"
Stack::Stack()
{
    top = -1;
}

void Stack::push(char x)
{
    if (top == MAX_SIZE - 1)
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    else
    {
        A[++top] = x;
    }
}

char Stack::pop()
{
    if (top != -1)
    {
        return A[top--];
    }
    else
    {
        return '\0';
    }
}

void Stack::isEmpty()
{
    if (top == -1)
    {
        std::cout << "Is Empty" << std::endl;
    }
    else
    {
        std::cout << "Not Empty" << std::endl;
    }
}
void Stack::topElement()
{
    std::cout << "The top element is : " << A[top];
}
void Stack::print()
{
    std::cout << "(";
    while (top != -1)
    {
        std::cout << pop();
        if (top != -1)
            std::cout << ",";        
    }
    std::cout << ") ";
}

Stack::~Stack()
{
}
