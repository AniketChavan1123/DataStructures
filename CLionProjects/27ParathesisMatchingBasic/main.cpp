#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isBalanced(char *exp)
{
    stack<char>stk;
    for(int i=0;i<strlen(exp);i++)
    {
        // ( found push to stack
        if(exp[i]=='(')
        {
            stk.push('(');
        }
        else if(exp[i]==')')
        {
            // ) and stack is empty
            if(stk.empty())
            {
                return false;
            }
            else{
                stk.pop();
            }
        }
    }
    // if stack is Empty then balanced else unbalanced

    return stk.empty();
}

int main() {
    char A[]="(a+b)*(cid)";
    cout<<" is balanced :";
    isBalanced(A)?cout<<"Yes":cout<<"No";
    return 0;
}
