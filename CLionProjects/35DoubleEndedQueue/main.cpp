#include <iostream>
using namespace std;
class DEQueue{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    explicit DEQueue(int size);
    ~DEQueue();
    void display() const;
    void enqueueFront(int x);
    void enqueueRear(int x);
    int deQueueFront();
    int dequeueRear();
    bool isEmpty() const;
    bool isFull() const;
};

DEQueue::DEQueue(int size) {
    this->size=size;
    front=-1;
    rear=-1;
    Q=new int[size];
}
DEQueue::~DEQueue() {
    delete[] Q;
}
bool DEQueue::isEmpty() const{
    if(front==rear)
    {
        return true;
    }return false;
}
bool DEQueue::isFull() const{
    if(rear==size-1)
    {
        return true;
    }return false;
}
void DEQueue::enqueueFront(int x) {
    if(front==-1)
    {
        cout<<"DEQueue Overflow"<<endl;
    }
    else{
        Q[front]=x;
        front--;
    }
}
void DEQueue::enqueueRear(int x) {
    if(isFull())
    {
        cout<<" DEQueue Overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int DEQueue::deQueueFront() {
    int x=-1;
    if(isEmpty())
    {
        cout<<"DEQueue Underflow"<<endl;
    }else{
        x=Q[++front];
    }
    return x;
}
int DEQueue::dequeueRear() {
    int x=-1;
    if(rear==-1)
    {
        cout<<"Dequeue Underflow"<<endl;
    }else
    {
        x=Q[rear];
        --rear;
    }return x;
}
void DEQueue::display() const{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<flush;
        if(i<rear)
        {
            cout<<"<-";
        }
    }
    cout<<endl;
}
int main() {
    int A[]={1,3,5,7,9};
    DEQueue deq(sizeof(A)/ sizeof(A[0]));
    for(int i:A)
    {
        deq.enqueueRear(i);
    }
    deq.display();
    deq.deQueueFront();
    deq.enqueueRear(10);
    deq.display();
    deq.deQueueFront();
    deq.enqueueFront(30);
    deq.enqueueFront(10);
    deq.display();
    deq.dequeueRear();
    deq.enqueueFront(90);
    deq.enqueueRear(90);
    deq.display();
    return 0;
}
