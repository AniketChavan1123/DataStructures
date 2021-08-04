#include <iostream>
using namespace std;
class Node{
public: int data;
    Node * next;
};
class LinkedList {
private:
    Node *head, *tail;

public:
    LinkedList() {
        tail = head = nullptr;
    }

    LinkedList(const int A[], int);
    virtual ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int length();
};
LinkedList::LinkedList(const int *A,int n)
{
//    an immutable object is an object whose state cannot be modified after it is created.
//    It makes sense to favor immutability where possible and to indicate immutable things with const.
//The warning means that your function does not modify the data pointed at by A and so the
// function could be better declared with pointer to const parameter
    Node *temp;
    int i;
    head=new Node;
    head->data=A[0];
    head->next=nullptr;
    tail=head;

    for(i=1;i<n;i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next=nullptr;
        tail->next=temp;
        tail=temp;
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

    void LinkedList::Display() {
    Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int LinkedList::length() {
    Node *temp=head;
    int len=0;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x) {
    Node *temp,*p=head;
    if(index<0||index>length())
    return;
    temp=new Node;
    temp->data=x;
    temp->next=nullptr;

    if(index==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        for (int i = 0; i < index-1; ++i) {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
int LinkedList::Delete(int index) {
    Node *p,*q= nullptr;
    int x;
    if(index<1 || index>length())
    return -1;
    if(index==1)
    {
        p=head;
        head=head->next;
        x=p->data;
        delete p;
    }
    else{
        p=head;
        for (int i = 0; i < index-1; ++i) {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
int main() {
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    l.Display();
    l.Insert(3,10);
    l.Display();
    l.Delete(2);
    l.Display();
    return 0;
}
