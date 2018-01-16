using namespace std;

#include <iostream>
#include <cstdlib>

#include "PostfixEvaluator.h"
#include "MYSTYLE.H"

PostfixEvaluator::PostfixEvaluator()
{
    //ctor
}

PostfixEvaluator::PostfixEvaluator(string s)
{
    _expr  = (char *) s.c_str();
    _index = 0;
}

char PostfixEvaluator::nextChar()
{
    char c =  *(_expr + _index);
    _index++;

    return c;
}

char PostfixEvaluator::processExpr()
{
    char c;
    char result;

    while ((c = nextChar()) != '\0')
    {
        if(charIsOperand(c))
            _stack.push(c);
        else
        {
            char pop1 = _stack.pop();
            char pop2 = _stack.pop();
            int op1 = pop1 - '0';
            int op2 = pop2 - '0';

            double res;

            switch(c)
            {
                case '*':
                    res = (double) op1 * op2;
                    break;
                case '/':
                    res = (double) op1 / op2;
                    break;
                case '%':
                    res = op1 % op2;
                    break;
                case '+':
                    res = (double) op1 + op2;
                    break;
                case '-':
                    res = (double) op1 - op2;
                    break;
            }

            result = res + 48;
            _stack.push(result);
        }
    }

    _index = 0;
    return _stack.peek();
}

bool PostfixEvaluator::isValid()
{
    char c;
    int charCtr = 0;
    int intCtr = 0;

    while ((c = nextChar()) != '\0')
    {
        if(charIsOperand(c))
            intCtr++;
        else if(charIsOperator(c))
            charCtr++;
        else
            return false;
    }

    _index = 0;
    return charCtr == --intCtr;
}

bool PostfixEvaluator::charIsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

bool PostfixEvaluator::charIsOperand(char c)
{
    return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0';
}

PostfixEvaluator::~PostfixEvaluator()
{
    //dtor
}
