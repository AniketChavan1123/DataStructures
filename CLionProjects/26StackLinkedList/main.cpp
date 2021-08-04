#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node *next;
};
class stack{
private:
    Node *top;
public:
    stack();
    ~stack();
    void push(int x);
    int pop();
    int peek(int index) const;
    int isEmpty() const;
    static int isFull() ;
    int stackTop() const;

    void display() const;
};

stack::stack() : top(nullptr) {}
stack::~stack() {
    Node *p=top;
    while(top)
    {
        top=top->next;
        delete p;
        p=top;
    }
}
void stack::push(int x){
    Node *t=new Node;
    if(t==nullptr)         // t could not be initiated as heap is full
    {
        cout<<"\nstack Overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int stack::pop() {
    Node *p;
    int x=-1;
    if(top== nullptr)
    {
        cout<<"\nStack Underflow";
    }
    else{
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}
int stack::isFull() {
    Node *t=new Node;
    int r=t?1:0;            // if t==null then r=0;
    delete t;
    return  r;
}
int stack::isEmpty() const {
    return top?0:1;
}
int stack::stackTop() const {
    if(top)
    {
        return top->data;
    }
    return -1;
}
int stack::peek(int index) const
{
    if(isEmpty())
    {
        return -1;
    }
    Node *p=top;
    for(int i=0;p!= nullptr && i<index-1;i++)
    {
        p=p->next;
    }
    if(p!= nullptr)
    {
        return p->data;
    }
    else{
        return -1;      //when reaches last Nodes
    }
}
void stack::display() const
{
    Node *p=top;
    while(p)
    {
        cout<<p->data;
        p=p->next;
        if(p)cout<<" - ";
    }
}
int main() {
    int A[]={1,3,5,7,9};
    stack stk;
    //populate stack
    for(int i : A)
    {
        stk.push(i);
    }
    cout<<"\nStack peek at 3rd :"<<stk.peek(3)<<endl;
    cout<<"\nStack Top :"<<stk.stackTop()<<endl;
    cout<<"\nStack Full :"<<stk.isFull()<<endl;
    cout<<"\nStack empty :"<<stk.isEmpty()<<endl;
    cout<<"\nAdd 34 :";
    stk.push(34);
    stk.display();
    cout<<"\ndelete 34 :"<<stk.pop()<<"\n";
    stk.display();

    //// POP out element from stack
    cout<<"\n Popped :"<<flush;
    for(int i:A)
    {
        cout<<stk.pop()<<","<<flush;
    }
    cout<<"\n isEmpty :"<<stk.isEmpty();
    cout<<endl;
    return 0;
}
