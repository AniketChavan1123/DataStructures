#include <iostream>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    explicit Queue(int size);
    ~Queue();
    bool isfull()const;
    bool isEmpty()const;
    void enqueue(int x);
    int dequeue();
    void display()const;
};
Queue::Queue(int size)
{
    this->size=size;
    rear=front=-1;
    Q=new int[size];
}
Queue::~Queue()
{
    delete[] Q;
}
bool Queue::isEmpty() const {
    if(front==rear)
        return true;
    return false;
}
bool Queue::isfull() const {
    if(rear==size-1)
    {
        return true;
    }
    else return false;
}
void Queue::enqueue(int x)
{
    if(isfull())
    {
        cout<<"Queue overflow";
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{
    int x=-1;
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
    }else{
        front++;
        x=Q[front];
    }
    return x;
}
void Queue::display()const{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<flush;
        if(i<rear)
        {
            cout<<"<-"<<flush;
        }
    }
    cout<<endl;
}

int main() {
    int A[]={1,3,5,7,9};
    Queue q(sizeof(A)/ sizeof(A[0]));

    //// Enqueue
    for(int i : A)
 {
        q.enqueue(i);
    }
    //Display
    q.display();

    //overflow
    q.enqueue(10);

    for(int i=0;i< (sizeof(A)/ sizeof(A[0]))-3;i++)
    {
        q.dequeue();
    }cout<<endl;
    q.display();
    return 0;
}
