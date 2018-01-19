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
        char pop();
        char peek();
        void print();
        void emptyStack();

        virtual ~MyStack();

    protected:

    private:
        int _N;
        int _ctr;
        char *_stack;
        static const int MAX = 10;

        void shiftStack(char *, int);
        void initializeStack(int);
};
