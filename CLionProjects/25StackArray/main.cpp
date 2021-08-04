#include <iostream>
using namespace std;
class stack{
private:
    int size;
    int top;
    int *S;
public:
    explicit stack(int size);
//    Clang-Tidy: Single-argument constructors must be marked explicit
//    to avoid unintentional implicit conversions--->explanation go to Concept folder
    ~stack();
    void push(int x);
    int pop();
    int peek(int index) const;
    int isFull() const;
    int isEmpty() const;
    void display() const;
    int stackTop();
};

stack::stack(int size)
{
    this->size=size;
    top=-1;
    S=new int[size];
}
stack::~stack()
{
    delete[] S;
}
void stack::push(int x)
{
    if(isFull())
    {
        cout<<"stack Overflow"<<endl;
    }
    else{
        top++;
        S[top]=x;
    }
}
int stack::pop(){
    int x=-1;
    if(isEmpty())
    {
        cout<<"stack Underflow"<<endl;
    }
    else{
        x=S[top];
        top--;
    }
    return x;
}
int stack::peek(int index) const
{
    int x=-1;
    if(top-index+1<0 || top-index+1==size)
    {
        cout<<"invalid position";
    }
    else {
        x = S[top - index + 1];       //let top=3 and we want element at 4th pos means top=0;
    }
    return x;
}
int stack::isEmpty() const {
    if(top==-1)
    {
//        top=top+1;        The object called by const function cannot be modified
        return 1;
    }
    return 0;
}
int stack::isFull() const
{
    if(top==size-1)
    {
        return 1;
    }
    return 0;
}
void stack::display() const
{
    for(int i=top;i>=0;i--)
    {
        cout<<S[i]<<"|"<<flush;
    }
    cout<<endl;
}
int stack::stackTop()
{
    if(isEmpty())
    {
        return -1;
    }
    return S[top];
}

int main() {
    int A[]={1,3,5,7,9};
    stack stk(sizeof(A)/ sizeof(A[0]));

    //populate stack with Array elements
    // object declared in main cannot access the private member directly
    for(int i : A)          // this is called rangebased loop
    {
        stk.push(i);
    }
    stk.push(11);           // overflow
    cout<<"Stack full "<<stk.isFull()<<endl;

    //Display Stack
    cout<<"Stack "<<flush;
    stk.display();

    //// peek
    cout<<"peek at 0 :"<<stk.peek(0);
    cout<<"\npeek at 1 :"<<stk.peek(1);

    //// TOP ELEMENT
    cout<<"\nTop element :"<<stk.stackTop()<<endl;

    //// PopOut element from Stack
    cout<<"popped out element :"<<flush;
    for(int i : A)
    {
        cout<<stk.pop()<<","<<flush;
    }
    return 0;
}
