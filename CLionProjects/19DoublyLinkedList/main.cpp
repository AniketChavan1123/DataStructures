#include <iostream>
using namespace std;
class Node{
public:
    Node *prev,*next;
    int data;
};
class DoublyLinkedList{
private:
    Node *head;
public:
    DoublyLinkedList();
    DoublyLinkedList(const int A[],int n);
    ~DoublyLinkedList();
    void display() const;
    int length() const;
    void insert(int index,int x);
    int deleteNode(int index);
    void iterativeReverse();
    void recursiveReverse(Node *q,Node *p);
    Node *getHead() const;
};
DoublyLinkedList::DoublyLinkedList() {
    head=new Node;
    head->prev= nullptr;
    head->next= nullptr;
    head->data=0;
    head->next= nullptr;
}
DoublyLinkedList::DoublyLinkedList(const int *A,int n) {
    Node *tail;
    head=new Node;
    head->prev= nullptr;
    head->data=A[0];
    head->next=nullptr;
    tail=head;

    for(int i=1;i<n;i++)
    {
        Node *t=new Node;
        t->prev=tail;
        t->next=tail->next;         // tail's next is pointing to Null
        t->data=A[i];
        tail->next=t;
        tail=t;
    }
}
void DoublyLinkedList::display() const
{
    Node *p=head;
    while(p!= nullptr)
    {
        cout<<p->data<<flush;
        p=p->next;
        if(p!= nullptr)             // great Idea
        {
            cout<<" <-> ";
        }
    }
    cout<<endl;
}
int DoublyLinkedList::length() const
{
    int length=0;
    Node *p=head;
    while(p!= nullptr)
    {
        length++;
        p=p->next;
    }
    return length;
}
void DoublyLinkedList::insert(int index,int x)
{
    if(index<0 || index>length())
    {
        return;
    }
    Node *p=head;
    Node *t=new Node;
    t->data=x;
    if(index==0)
    {
        t->prev= nullptr;
        t->next=head;
        head->prev=t;
        head=t;             // even if head is null, head is created
//        if i make insert function and length function const the head=t giver error like
//  Cannot assign to non-static data member within const member function 'insert'
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}
int DoublyLinkedList::deleteNode(int index) {
    int x=-1;
    Node *p=head;
    if(index<0 || index>length())
    {
        return x;
    }
    if(index==1)
    {
        head=head->next;
        if(head)        // if head !null then delete prev head
        {
            head->prev= nullptr;        // breaking relationship with previous head
        }
        x=p->data;
        delete p;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}
void DoublyLinkedList::iterativeReverse() {
    Node *p=head;
    Node *temp;
    while(p!= nullptr)      // will not enter if head=nullptr
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p->next == nullptr)   // to check if further Node is available or not ..if not break the loop
        {
            p->next = p->prev;
            p->prev = nullptr;
            head = p;
            break;
        }
    }
}
void DoublyLinkedList::recursiveReverse(Node *q,Node *p) {
    if(p== nullptr)
    {
        head=q;
        return;
    }
    else{
        recursiveReverse(p,p->next);
        p->prev=p->next;
        p->next=q;
    }
//    tail=p;
}
DoublyLinkedList::~DoublyLinkedList() {
    Node *p=head;
    while(head)
    {
        head=head->next;
        delete p;
        p=head;
    }
}

Node *DoublyLinkedList::getHead() const {
    return head;
//    The object called by these functions cannot be modified.
//    It is recommended to use const keyword so that accidental changes to object are avoided.
//    V.Imp->When a function is declared as const, it can be called on any type of object.
//    Non-const functions can only be called by non-const objects.
//  A const object declared in main cannot call non-const function of class;
// a const member function can only call constant member function
// A constructor cannot be const-> because then it will not be able to initialize non-constant members
}
//Like member functions and member function arguments, the objects of a class can also be declared as const.
// an object declared as const cannot be modified and hence, can invoke only const member functions as
// these functions ensure not to modify the object.
//A const object can be created by prefixing the const keyword to the object declaration.
// Any attempt to change the data member of const objects results in a compile-time error.

int main() {
    int A[]={1,3,5,7,9};
    DoublyLinkedList dll(A,sizeof(A)/sizeof(A[0]));
    cout<<"length :"<<dll.length()<<endl;
    cout<<" Adding 11,13 and 14: ";
    dll.insert(0,11);   // first
    dll.insert(6,13);   // last
    dll.insert(3,14);   // middle
    dll.display();
    cout<<" deleting 11,9 and 5: ";
    dll.deleteNode(1);  // deleting first
    dll.deleteNode(6);  // deleting last
    dll.deleteNode(4);  // deleting middle
    dll.display();
    cout<<"\nReversing list with iterative process :";
    dll.iterativeReverse();
    dll.display();
    cout<<"\nReversing list with Recursive process :";
    dll.recursiveReverse(nullptr,dll.getHead());
    dll.display();
    dll.deleteNode(1);  // deleting first
    dll.deleteNode(4);  // deleting last
    dll.deleteNode(2);  // deleting middle
    dll.display();
    dll.recursiveReverse(nullptr,dll.getHead());
    dll.display();
    dll.deleteNode(2);  // deleting middle
    dll.display();
    return 0;
}
