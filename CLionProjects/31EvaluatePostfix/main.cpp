#include <iostream>
#include<stack>
using namespace std;

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else{
        return 1;
    }
}
int Eval(const char* postfix)
{
    stack<char>stk;
    int i;
    int x1,x2,r=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            stk.push(postfix[i]-'0');
        }else{
            x2=(unsigned char)stk.top();
            stk.pop();
            x1=stk.top();//'signed char' to 'int' conversion; consider casting to 'unsigned char' first.
            //Signed character data must be converted to unsigned char before being assigned or converted
            // to a larger signed type. This rule applies to both signed char and
            // (plain) char characters on implementations where char is defined to have the same range,
            // representation, and behaviors as signed char.
            //
            //However, this rule is applicable only in cases where the character data may contain values
            // that can be interpreted as negative numbers. For example, if the char type is represented by
            // a two's complement 8-bit value,
            // any character value greater than +127 is interpreted as a negative value.
            stk.pop();
                    switch(postfix[i])
                    {
                        case '+':r=x1+x2;
                            break;
                        case '-':r=x1-x2;
                            break;
                        case '*':r=x1*x2;
                            break;
                        case '/':r=x1/x2;
                            break;
                    }
                    stk.push(r);
        }
    }
    return stk.top();
}

int main() {
    const char* postfix="35*62/+4-";
    cout<<Eval(postfix);
    return 0;
}
