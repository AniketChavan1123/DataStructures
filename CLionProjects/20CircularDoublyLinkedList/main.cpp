#include <iostream>
using namespace std;

class Node{
public:
    Node *prev,*next;
    int data;
};
class circularDll{
private:
    Node *head;
public:
    circularDll();
    circularDll(const int A[],int n);
    ~circularDll();
    void display();
    int length();
    void insert(int index,int x);
    int deleteNode(int index);
    void iterativeReverse();
    void displayReverse();
    void recursiveReverse(Node *q, Node *p);

    Node *getHead() const;
};
circularDll::circularDll() {
    head=new Node;
    head->prev=head;
    head->next=head;
}
circularDll::circularDll(const int *A, int n) {
    head=new Node;
    head->prev=head;
    head->next=head;
    head->data=A[0];
    Node *tail=head;
    for(int i=1;i<n;i++)
    {
        Node *t=new Node;
        t->prev=tail;
        t->data=A[i];
        tail->next=t;
        tail=t;
        tail->next=head;
        head->prev=tail;
    }
}
circularDll::~circularDll() {
    Node *p=head;
        while(head){
        if(head->next==head){
        delete head;
        head= nullptr;
        }
        else{
            head->prev->next=head->next;
            head->next->prev=head->prev;
            head=head->next;
            delete p;
            p=head;
        }
    }
        cout<<"\n Destructor executed successfully";
}
void circularDll::display()
{
    Node *p=head;
    int flag=0;
    if(head== nullptr)
        return;
    else {
        while (p != head || flag == 0) {
            flag = 1;
            cout << p->data << flush;
            p = p->next;
            if (p != head) {
                cout << " <-> " << flush;
            }
        }
        cout<<endl;
    }
}
void circularDll::displayReverse()
{
    Node *p=head;
    int flag=0;
    if(head== nullptr)
        return;
    else {
        while (p != head || flag == 0) {
            flag = 1;
            cout << p->data << flush;
            p = p->prev;
            if (p != head) {
                cout << " <-> " << flush;
            }
        }
        cout<<endl;
    }
}
int circularDll::length(){
    int length=0;
    Node *p=head;
    if(head== nullptr)
        return length;
    int flag=0;
    while(p!=head||flag==0)
    {
        flag=1;
        length++;
        p=p->next;
    }return length;
}

void circularDll::insert(int index, int x) {
    Node *p=head;
    if(index<0 || index>length())
        return;
    if(index==0)
    {
        Node *t=new Node;
        t->data=x;
        head->prev->next=t;
        t->prev=head->prev;
        head->prev=t;
        t->next=head;
        head=head->prev;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        Node *t=new Node;
        t->prev=p;
        t->data=x;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
    }
}
int circularDll::deleteNode(int index) {
    int x=-1;
    Node *p=head;
    if(index<0 || index>length() || head== nullptr)
        return x;
    if(index==1)
    {
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        x=p->data;
        delete p;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}
void circularDll::iterativeReverse() {
    Node *p=head;
    Node *temp;
    int flag=0;
    while(p!=head || flag==0)
    {
        flag=1;
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
    }
}
void circularDll::recursiveReverse(Node *q,Node *p) {
    if(p!=head)
    {
        recursiveReverse(p,p->next);
    }
    p->next=q;
    q->prev=p;
}

Node *circularDll::getHead() const {
    return head;
}

int main() {
    int A[]={1,3,5,7,9};
    circularDll cdll(A,5);
    cdll.display();
    cout<<"Inserting 74 at first : ";
    cdll.insert(0,74);
    cdll.display();
    cout<<"Inserting 84 at last : ";
    cdll.insert(cdll.length(),84);
    cdll.display();
    cout<<" Inserting 4 at 2nd position : ";
    cdll.insert(2,4);
    cdll.display();
    cout<<"deleting first Node :";
    cdll.deleteNode(1);
    cdll.display();
    cout<<"deleting last Node : ";
    cdll.deleteNode(cdll.length());
    cdll.display();
    cout<<" deleting from 2nd Position :";
    cdll.deleteNode(2);
    cdll.display();
    cout<<"display in Reverse: ";
    cdll.displayReverse();
    cout<<"\n Reversed CDLL: ";
    cdll.iterativeReverse();
    cdll.display();
    cout<<"\n recursive reverse of CDLL: ";
    cdll.recursiveReverse(cdll.getHead(),cdll.getHead()->next);
    cdll.display();
    cdll.displayReverse();
    cout<<"\nlength : "<<cdll.length();
    return 0;
//    When you create your object on the heap, you kinda need to delete your class before its
//    destructor is called and memory is freed:
//
//int main()
//{
//  date* ob2 = new date(12);
//  // ob2->day holds 12
//  delete ob2; // ob2's destructor will get called here, after which it's memory is freed
//  return 0;   // ob2 is invalid at this point.
//}
}
