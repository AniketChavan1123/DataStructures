#include <iostream>
using namespace std;
class Job{
public:
    char task;
    int priority;
};

class Node{
public:
    char Task;
    Node *next;
};

class PQ{
private:
    Node **A;
    Node **tail;
    Job *obj;
public:
    PQ();
    ~PQ();
    void insert();
    void segregation();
    void display() const;
};
PQ::PQ() {
    A=new Node*[10];
    obj=new Job[10];
    tail=new Node* [10];
}
PQ::~PQ() {
    int i=0;
    Node *temp;
    while(A[i]!= nullptr)
    {
        Node *p=A[i];
        while(p!= nullptr)          // deleting inside linked list
        {
            temp=p;
            delete p;
            p=temp->next;
        }
        i++;
    }
    delete[] A;         // for deleting A, it has to be pointer
    delete[] obj;
}
void PQ::display() const{
    int i=0;
    while(A[i]!= nullptr)
    {
        Node *p=A[i];
        while(p!= nullptr)
        {
            cout<<p->Task;
            if(p->next)
            {
                cout<<"->";
            }
            p=p->next;
        }
        i++;
        if(A[i])
        {
            cout<<"->";
        }
    }
}
void PQ::insert() {
    for(int i=0;i<10;i++)
    {
        cout<<"Enter obj "<<i<<" task and priority ";
        cin>>obj[i].task;
        cin>>obj[i].priority;
        cout<<endl;
    }
}
void PQ::segregation() {
    for(int i=0;i<10;i++)
    {
        Node *t=new Node;
        t->Task=obj[i].task;
        t->next= nullptr;
        if(A[obj[i].priority-1]== nullptr)
        {
            A[obj[i].priority-1]=tail[obj[i].priority-1]=t;
        }else{
            tail[obj[i].priority-1]->next=t;
            tail[obj[i].priority-1]=t;
        }
    }
}
int main() {
    PQ pq;
    pq.insert();
    pq.segregation();
    pq.display();
    return 0;
}
