#include <iostream>

using namespace std;

class MyStack
{
    public:
        MyStack();
        MyStack(int);

        bool isEmpty();
        bool isFull();

        void push(char);
        void emptyStack();
        void print();
        char peek();
        char pop();

        virtual ~MyStack();

    protected:

    private:
        int _N;
        int _ctr;
        char *_stack;
        static const int MAX = 10;

        void initializeStack(int);
};
