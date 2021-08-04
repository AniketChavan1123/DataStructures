// finding loop in linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
}*first=nullptr;        // first is like global
void Display(Node *p)
{
    while(p!=nullptr)
    {
        cout<<p->data;
        p=p->next;
    }
}
void create(const int A[],int n)
{
    int i;
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=nullptr;
    last=first;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}
int isLoop(Node *p)
{
    Node *q;
    q=p;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}
int main()
{
    Node *t1,*t2;

    int A[]={10,20,30,40,50};
    create(A,5);
    Display(first);
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    cout<<"\n"<<isLoop(first);


    return 0;
}