#include <iostream>
using namespace std;
class Node{
public: int data;
    Node * next;
};
class LinkedList {
public:
    Node *head, *tail;

    LinkedList() {
        tail = head = nullptr;
    }
    virtual ~LinkedList();
    void SortedInsert(Node *p,int x);
    static void RecursiveDisplay(Node *p);
    static void RemoveDuplicates(Node *p);
    //useful when you don't want to create an
    //instance of an object just to execute one public function on it
    // A static member function is a special member function,
    // which is used to access only static data members( function or variables),
    // any other normal data member cannot be accessed through static member function.
    // Just like static data member ,static member function is also a class function;
    // it is not associated with any class object.
    void SlidingReverse(Node *p);

    void RecursiveReverse(Node *p);

    void AltRecursiveReverse(Node *q, Node *p);
};
void LinkedList::SortedInsert(Node *p, int x) {
    Node *temp,*q;
    temp=new Node;
    temp->next= nullptr;
    temp->data=x;
    if(head== nullptr)
    {
        head=tail=temp;
    } else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            temp->next=head;
            head=temp;
        }
        else{
            temp->next=p;
            q->next=temp;
        }
    }
}
LinkedList::~LinkedList(){
    Node *p=head;
    while(head)
    {
        head=head->next;
        delete p;
        p=head;
    }
}
void LinkedList::RecursiveDisplay(Node *p)
{
    if (p != nullptr) {
    cout << p->data;  // Forward Display
    RecursiveDisplay(p->next);
//        cout << p->data;  // Reverse Display
    }
}
void LinkedList::RemoveDuplicates(Node *p)
{
    Node *q=p->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void LinkedList::SlidingReverse(Node *p)
{
    tail=p;
    Node *r,*q= nullptr;
    while (p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
void LinkedList::RecursiveReverse(Node *p)
{
    Node *q= nullptr;
    if(p==tail)
    {
        head=p;
        return;
    }
    else{
            q=p;
            p=p->next;
            RecursiveReverse(p);
            p->next=q;
            q->next= nullptr;
            tail=q;
        }
}
void LinkedList::AltRecursiveReverse(Node *q,Node *p)
{
    if(p)
    {
        AltRecursiveReverse(p,p->next);
        p->next=q;  // at return time p backtracks to tail position and q to p's revious position
        tail=p;
    }
    else
        head=q;
}
int main() {
    LinkedList l;
    l.SortedInsert(l.head,2);
    l.SortedInsert(l.head,1);
    l.SortedInsert(l.head,7);
    l.SortedInsert(l.head,7);
    l.SortedInsert(l.head,5);
    l.SortedInsert(l.head,9);
    l.SortedInsert(l.head,9);
    l.SortedInsert(l.head,4);
    l.SortedInsert(l.head,4);
    l.SortedInsert(l.head,7);
    l.SortedInsert(l.head,5);
    l.SortedInsert(l.head,9);
    l.SortedInsert(l.head,9);
    l.SortedInsert(l.head,4);
    l.SortedInsert(l.head,4);
    l.RecursiveDisplay(l.head);
    LinkedList::RemoveDuplicates(l.head);
    cout<<"\nRemoving Duplicates : ";
    LinkedList::RecursiveDisplay(l.head);
    l.SlidingReverse(l.head);
    cout<<"\nSliding Reverse : ";
    l.RecursiveDisplay(l.head);
    cout<<"\t"<<l.head->data<<"\t"<<l.tail->data;
    l.RecursiveReverse(l.head);
    cout<<"\nRecursiveReverse :";
    l.RecursiveDisplay(l.head);
    cout<<"\t"<<l.head->data<<"\t"<<l.tail->data;
    l.AltRecursiveReverse(nullptr,l.head);
    cout<<"\nAltRecursiveReverse :";
    l.RecursiveDisplay(l.head);
    cout<<"\t"<<l.head->data<<"\t"<<l.tail->data;



    return 0;
}
