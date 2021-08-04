#include <iostream>
#include<cstring>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
}*top= nullptr;

void push(char x)
{
    Node *t=new Node;
    if(t== nullptr)
    {
        cout<<"stack is Full";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    Node *t=top;
    char x=-1;
    if(top== nullptr)
    {
        cout<<"Stack is Empty";
    }
    else{
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}
int isBalanced(const char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++) {
        if (exp[i] == ')') {
            push(')');
        }
        else if(exp[i]==')')
        {
            if(top== nullptr)
                return 0;
            pop();
        }
    }
    if(top== nullptr)           // to check whether stack has become empty
    {
        return 1;
    }return 0;
}
int precedence(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    return 1;
}
char* InToPost(const char* infix)
{
    int i=0,j=0;
    char* postfix;
    int len=strlen(infix);
    postfix=new char[len+2];        //one for'\0' and one for #

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(top->data))
                push(infix[i++]);       // top doesn't become null so we introduced #
            else{
                postfix[j++]=pop();// we have not increased i bcz we need to pop both out so we need
                // infix[i] 2 times
            }
        }
    }
    while(top->data!='#')        //top->data!='#'
    {
        postfix[j++]=pop();
        postfix[j]='\0';
    }
    return postfix;
}

int main() {
    const char *infix="a+b*c-d/e";
// with char *infix :ISO C++11 does not allow conversion from string literal to 'char *'
    if(isBalanced(infix))
    {
        push('#');
        char *postfix=InToPost(infix);
        cout<<postfix;
    }
    return 0;
}
////NOTE:
//char *s = "geeksquiz";
//printf("%lu", sizeof(s));
//
//// Uncommenting below line would cause undefined behaviour
//// (Caused segmentation fault on gcc)
////  s[0] = 'j';
// C string literals are arrays of char but
//in C++ they are constant array of char
//A string literal is a bit of text between double quotes,This quote has a type of const char *
//
//(a) You cannot change it, but can access its value (const).
//(b) A C++ compiler handles it much like it would a character array (char *).