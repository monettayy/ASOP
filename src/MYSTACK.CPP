#include "MyStack.h"

MyStack::MyStack()
{
    initializeStack(MAX);
}

MyStack::MyStack(int n)
{
    initializeStack(n);
}

bool MyStack::isEmpty()
{
    return _ctr == 0 ? true : false;
}

bool MyStack::isFull()
{
    return _ctr > _N ? true : false;
}

void MyStack::push(char c)
{
    _ctr++;

    if(isFull())
        _N *= 2;

    char *temp = new char[_N];
    temp[0] = c;

    for(int i=1; i<_ctr; i++)
        temp[i] = _stack[i-1];

    delete[] _stack;
    _stack = temp;
}

char MyStack::pop()
{
    _ctr--;

    char *temp = new char[_N];
    char popValue = *_stack++;

    for(int i=0; i<_ctr; i++)
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
        cout << "Stack is now empty";
    else
        for(int i=0; i<_ctr; i++)
            cout << _stack[i] << " ";

    cout << endl;
}

void MyStack::emptyStack()
{
    initializeStack(MAX);
}

void MyStack::initializeStack(int n)
{
    _N = n;
    _ctr = 0;
    _stack = new char[_N];
    _stack = NULL;
}

MyStack::~MyStack()
{
    delete[] _stack;
    _stack = NULL;
}
