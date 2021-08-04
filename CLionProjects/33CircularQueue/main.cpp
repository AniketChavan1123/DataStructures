#include <iostream>

using namespace std;
class circularQueue{
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    explicit circularQueue(int size);
    ~circularQueue();
    bool isfull() const;
    bool isEmpty() const;
    void enqueue(int x);
    int dequeue();
    void display() const;
};

circularQueue::circularQueue(int size) {
    this->size=size;
    front=0;
    rear=0;
    Q=new int[size];
}

circularQueue::~circularQueue() {
    delete[] Q;
}
bool circularQueue::isEmpty() const {
    if(front==rear)
    {
        return true;
    }
    return false;
}
bool circularQueue::isfull() const {
    if((rear+1)%size==front)
    {
        return true;
    }return false;
}

void circularQueue::enqueue(int x)
{
    if(isfull())
    {
        cout<<"Queue overflow"<<endl;
    }else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}
int circularQueue::dequeue()
{
    int x=-1;
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
    }else{
        front=(front+1)%size;
        x=Q[front];
    }return x;
}

void circularQueue::display() const
{
    int i=front+1;
    do{
        cout<<Q[i]<<flush;
        if(i!=rear)
        {
            cout<<"<-"<<flush;
        }
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
}
int main() {
    int A[]={1,3,5,7,9};
    circularQueue q(sizeof(A)/ sizeof(A[0])+1);

    //enqueue
    for(int i : A)
    {
        q.enqueue(i);
    }
    q.display();
    cout<<endl;
    q.dequeue();
    q.enqueue(43);
    cout<<"\nAdding 43 at first :";
    q.display();
    return 0;
}
