#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

class MyStack
{
    public:
        MyStack();
        MyStack(int);

        bool isEmpty();
        bool isFull();
        void emptyStack();
        void push(char);
        char pop();
        char peek();
        void print();

        virtual ~MyStack();

    protected:

    private:
        int N;
        int ctr;
        const int MAX = 10;
        char *_stack = NULL;

        void initializeStack();
};

#endif // MYSTACK_H
