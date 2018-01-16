#include <iostream>
#include <cstdlib>

using namespace std;

#include "MyStack.h"
#include "MyStyle.h"

MyStack::MyStack()
{
    N = MAX;
    initializeStack();
}

MyStack::MyStack(int N)
{
    this->N = N;
    initializeStack();
}

bool MyStack::isEmpty()
{
    return ctr == 0 ? true : false;
}

bool MyStack::isFull()
{
    return ctr < N ? false : true;
}

void MyStack::emptyStack()
{
    delete[] _stack;
    _stack = NULL;
    N = MAX;
    initializeStack();
}

void MyStack::push(char c)
{
    if(isFull())
        N *= 2;

    char *temp = new char[N];

    int i;
    temp[0] = c;
    for(int i=1; i<=ctr; i++)
        temp[i] = _stack[i-1];

    delete[] _stack;
    _stack = temp;

    ctr++;
}

char MyStack::pop()
{
    ctr--;
    char *temp = new char[N];

    char popValue = *_stack++;
    for(int i=0; i<ctr; i++)
        temp[i] = _stack[i];

    delete[] _stack;
    _stack = temp;

    return popValue;
}

char MyStack::peek()
{
    return *_stack;
}

void MyStack::print()
{
    if(isEmpty())
        MyStyle::centerText("Stack is now empty");
    else
    {
        MyStyle::centerTextAsk("", ctr + (ctr-1));
        for(int i=0; i<ctr; i++)
            cout << _stack[i] << " ";
        cout << endl;
    }
}

void MyStack::initializeStack()
{
    ctr = 0;
    _stack = new char[N];
    for(int i=0; i<N; i++)
        _stack[i] = NULL;
}

MyStack::~MyStack()
{
    delete[] _stack;
    _stack = NULL;
}
