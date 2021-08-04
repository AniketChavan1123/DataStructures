#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};
Queue::Queue()
{
    front= nullptr;
    rear= nullptr;
}
void Queue::enqueue(int x)
{
    Node *t=new Node;
        t->data=x;
        t->next= nullptr;
        if(front== nullptr)
        {
            front=rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
}
int Queue::dequeue() {
    int x=-1;
    Node *p;
    if(isEmpty())
    {
        cout<<"Queue underflow "<<endl;
    }else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}
bool Queue::isEmpty() {
    if(front== nullptr)
    {
        return true;
    }return false;
}
Queue::~Queue() {
    Node *p=front;
    while(front)
    {
        front=front->next;
        delete p;
        p=front;
    }
}
void Queue::display() {
    Node *p=front;
    while(p)
    {
        cout<<p->data<<flush;
        p=p->next;
        if(p!= nullptr)
        {
            cout<<"<-"<<flush;
        }
    }cout<<endl;
}
int main() {
    int A[]={1,3,5,7,9};
    Queue q;
    for(int i : A)
    {
        q.enqueue(i);
    }
    q.display();
    for(int i=0;i< sizeof(A)/ sizeof(A[0]);i++)
    {
        cout<<q.dequeue();
    }
    q.dequeue();
    return 0;
}
