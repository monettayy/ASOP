#include "PostfixEvaluator.h"

PostfixEvaluator::PostfixEvaluator()
{
    _index = 0;
    _expr = NULL;
}

PostfixEvaluator::PostfixEvaluator(string s)
{
    _index = 0;
    _expr  = (char *) s.c_str();
}

bool PostfixEvaluator::isValid()
{
    char c;
    int intCtr = 0;
    int charCtr = 0;

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
    return c == '+' || c == '-' ||
           c == '*' || c == '/' || c == '%';
}

bool PostfixEvaluator::charIsOperand(char c)
{
    return c == '1' || c == '2' || c == '3' ||
           c == '4' || c == '5' || c == '6' ||
           c == '7' || c == '8' || c == '9' ||
           c == '0';
}

char PostfixEvaluator::nextChar()
{
    char c =  *(_expr + _index);
    _index++;

    return c;
}

int sum(int x, int y)
{
    return x + y;
}

int difference(int x, int y)
{
    return x - y;
}

int product(int x, int y)
{
    return x * y;
}

int qoutient(int x, int y)
{
    return x / y;
}

int mod(int x, int y)
{
    return x % y;
}

char PostfixEvaluator::processExpr()
{
    char c;

    while ((c = nextChar()) != '\0')
    {
        if(charIsOperand(c))
            _stack.push(c);
        else
        {
            int op1 = _stack.pop() - '0';
            int op2 = _stack.pop() - '0';
            int (* o) (int, int) = NULL;

            switch(c)
            {
                case '*': o = product;      break;
                case '/': o = qoutient;     break;
                case '%': o = mod;          break;
                case '+': o = sum;          break;
                case '-': o = difference;   break;
            }

            int intResult = o(op1, op2);
            char charResult = intResult + '0';

            _stack.push(charResult);
        }
    }

    _index = 0;
    return _stack.peek();
}

PostfixEvaluator::~PostfixEvaluator()
{
}
