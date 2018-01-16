#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "MyStack.h"

class PostfixEvaluator
{
    public:
        PostfixEvaluator();
        PostfixEvaluator(string);

        char processExpr();

        bool isValid();
        bool charIsOperator(char);
        bool charIsOperand(char);
        virtual ~PostfixEvaluator();
    protected:
    private:
        MyStack _stack;
        char *_expr;
        int _index;
        char nextChar();
};

#endif // POSTFIXEVALUATOR_H
