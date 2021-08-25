#ifndef Stack_hpp
#define Stack_hpp

#define MAX_SIZE 50
#include <iostream>
class Stack
{

public:
    char A[MAX_SIZE];
    int top;

    Stack();

    void push(char x);
    char pop();
    void topElement();
    void print();
    void isEmpty();

    ~Stack();
};
#endif