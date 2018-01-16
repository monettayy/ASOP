#include <iostream>

#include "PostfixEvaluator.h"

using namespace std;

int main()
{
    PostfixEvaluator p("123*+");

    if(p.isValid())
    {
        char result = p.processExpr();
        cout << result;
    }
    else
        cout << "Invalid";

    return 0;
}
