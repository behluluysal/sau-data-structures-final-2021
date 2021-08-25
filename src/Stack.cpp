#include "Stack.hpp"
Stack::Stack()
{
    top = -1;
}

void Stack::push(char x)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
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
        cout << "Is Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }
}
void Stack::topElement()
{
    cout << "The top element is : " << A[top];
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
