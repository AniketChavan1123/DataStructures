#include <iostream>
#include<stack>
using namespace std;
class Queue{
private:
    stack<int>eStk;         // enquque stack
    stack<int>dStk;
public:
    void enqueue(int x);
    int dequeue();
};
void Queue::enqueue(int x) {
    eStk.push(x);
}

int Queue::dequeue() {
    int x=-1;
    if(dStk.empty())
    {
        if(eStk.empty())
        {
            cout<<"Queue Underflow"<<endl;
            return x;
        }else{
            while(!eStk.empty())
            {
                dStk.push(eStk.top());
                eStk.pop();
            }
        }
    }
    x=dStk.top();
    dStk.pop();
    return x;
}
int main() {
    int A[]={1,3,5,7,9};
    Queue q;
    cout<<"Enqueue:"<<flush;
    for(int i=0;i< sizeof(A)/ sizeof(A[0]);i++)
    {
        q.enqueue(A[i]);
        cout<<A[i]<<flush;
        if(i< sizeof(A)/ sizeof(A[0])-1)
        {
            cout<<"<-"<<flush;
        }
    }cout<<endl;
    cout<<"Dequeue :"<<flush;
    for(int i=0;i< sizeof(A)/ sizeof(A[0]);i++)
    {
        cout<<q.dequeue()<<flush;
        if(i< sizeof(A)/ sizeof(A[0])-1)
        {
            cout<<"<-"<<flush;
        }
    }
    return 0;
}
