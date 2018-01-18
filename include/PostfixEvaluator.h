#include <iostream>

using namespace std;

#include "MyStack.h"

class PostfixEvaluator
{
    public:
        PostfixEvaluator();
        PostfixEvaluator(string);

        bool isValid();
        bool charIsOperator(char);
        bool charIsOperand(char);

        char processExpr();

        virtual ~PostfixEvaluator();

    protected:

    private:
        int _index;
        char *_expr;
        MyStack _stack;

        char nextChar();
};
