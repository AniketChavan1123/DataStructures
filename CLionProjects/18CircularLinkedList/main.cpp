// Circular Linked List
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
class CircularLinkedList{
private:
    Node *head;
public:
    CircularLinkedList(const int A[],int n);
    void display();
    void recursiveDisplay(Node *p);
    Node* getHead()
    {
        return head;
    }
    ~CircularLinkedList();

    void Insert(int pos, int x);

    int length(Node *p);

    int deleteNode(int pos);

    void recursiveReverse(Node *q, Node *p);

    void iterativeReverse();
};
CircularLinkedList::CircularLinkedList(const int *A, int n) { //A is a pointer to an array of 5 int=int (*A)[5].
//"a" is a pointer to the array of 5 integers, in other words "a" points to an array that holds 5 integers.
    Node* t;
    Node *tail;
    head=new Node;
//    A[0]=234;     Error: Read only variable is not assignable
    head->data=A[0];
    head->next=head;
    tail=head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=tail->next;         // connecting to head
        tail->next=t;
        tail=t;
    }
}
void CircularLinkedList::display() {
    Node* p=head;
    do{
        cout<<p->data<<" "<<flush;
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
void CircularLinkedList::recursiveDisplay(Node *p) {
    static  int flag=0;             // first time the head should not become null
    if(p!=head || flag ==0)
    {
        flag=1;
        cout<<p->data<<" "<<flush;
        recursiveDisplay(p->next);
    }
}
CircularLinkedList::~CircularLinkedList() {
    Node *p=head;
    while(p->next!=head)
    {
        p=p->next;      // to get at tail's position
    }
    while(p!=head)          // while tail does not become head
    {
        p->next=head->next;
        delete head;
        head=p->next;
    }
    if(p==head)
    {
        delete head;
        head= nullptr;
    }
}
int CircularLinkedList::length(Node *p)
{
    int length=0;
    do{
        length++;
        p=p->next;
    }while(p!=head);
    return length;
}
void CircularLinkedList::Insert(int pos,int x)
{
    Node *t,*p;
    if(pos<0 || pos>length(head))
        return;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        if(head== nullptr)
        {
            head=t;
            head->next=head;        // because this is circular LinkedList
        }
        else{
            p=head;
            while(p->next!=head)        //going to last Node that is tail
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
//            head=t;   this step is not compulsory
        }
    }
    else{
        p=head;
        for(int i=1;i<pos-1;i++)            // Inserting at position number
        {
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int CircularLinkedList::deleteNode(int pos)
{
    Node *p,*q;
    int x;
    if(pos<0 || pos>length(head))
        return -1;
    if(pos==1)
    {
        p=head;
        while(p->next!=head)           // to reach at tail
        {
            p=p->next;
        }
        x=p->data;
        if(p==head)     // if CLL only consist as it's Node
        {
            delete head;
            head= nullptr;
        }
        else{
            p->next=head->next;     // as position is 1 i.e head
            delete head;
            head=p->next;
        }
    }
    else{
        p=head;
        for(int i=0;i<pos-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}
void CircularLinkedList::recursiveReverse(Node *q,Node *p)
{
    if(head== nullptr)
        return;
    else if(p!=head)
    {
      recursiveReverse(p,p->next);
    }
    else{
        head=q;
    }
    p->next=q;
}
void CircularLinkedList::iterativeReverse() {
    Node *p,*r,*temp;
    if(head== nullptr)                  // explanation in Notebook
        return;
    else{
        temp=head;
        p=head->next;
        r=p->next;
        while(temp!=r)
        {
            p->next=temp;
            temp=p;
            p=r;
            r=r->next;
        }
        head=temp;
    }
}
int main() {
    int A[]={1,5,10,15,20};
    CircularLinkedList l(A,5);
    l.display();
    Node *h=l.getHead();
    l.display();
    cout<<"Insert 13 at 4th Position :";
    l.Insert(4,13);
    l.recursiveDisplay(h);
    cout<<"\ndeleting 4th element "<<l.deleteNode(4)<<" : ";
    l.display();
    cout<<"Recursive Reverse: ";
    l.recursiveReverse(l.getHead(),l.getHead()->next);
    l.display();
    cout<<"\nIterative Reverse: ";
    l.iterativeReverse();
    l.display();
    return 0;
}
