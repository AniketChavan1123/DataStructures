#include <iostream>
using namespace std;
class PQueue{
    int *A;
    int front;
public:
    PQueue();
   ~PQueue();
    void assignJob(int job);
    void dequeue();
    void display();
};
PQueue::PQueue() {
    front=-1;
    A=new int[10];
}
PQueue::~PQueue() {
    delete A;
}
void PQueue::assignJob(int job) {
    static int flag=1;
    static int count=0;
    if(flag)
    {
        A[0]=job;
        flag=0;
    }else{
        int j=0;
        while(job>A[j] && j<=count)                 // SEARCHING: O(n)
        {
            j++;
        }
        int k=count+1;
        for(int i=j;i<=count;i++)                   // SHIFTING: 0(n)
        {
            A[k]=A[k-1];
            --k;
        }
        A[j]=job;
        count++;
    }

}
void PQueue::display()
{
    cout<<endl;
    for(int i=front+1;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
}
void PQueue::dequeue() {
    front++;
}

int main() {
    PQueue pq;
    int j;
    for(int i=0;i<10;i++)
    {
        cin>>j;
        pq.assignJob(j);
    }
    pq.display();
    pq.dequeue();
    pq.display();
    return 0;
}
