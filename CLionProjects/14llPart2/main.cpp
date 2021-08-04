#include <iostream>
using namespace std;
class Node{
public: int data;
    Node * next;
};
class LinkedList {
public:
    Node *head,*tail;
    LinkedList() {
        tail = head = nullptr;
    }

    LinkedList(const int A[], int);
    virtual ~LinkedList();
    void RecursiveDisplay(Node *p);
    int RecursiveLength(Node *p);
    int RecursiveAdd(Node *p);
    int RecursiveMax(Node *p);
    int RecursiveMin(Node *p);
    Node* ImprovedSearching(Node* p,int key);
    static bool isSorted(Node *p);
};
LinkedList::LinkedList(const int *A,int n)
{
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
int LinkedList::RecursiveLength(Node *p) {
    if(p==nullptr)
        return  0;
    return RecursiveLength(p->next)+1;
}
void LinkedList::RecursiveDisplay(Node *p) {
    if (p != nullptr) {
        cout << p->data;  // Forward Display
        RecursiveDisplay(p->next);
//        cout << p->data;  // Reverse Display
    }
}
int LinkedList::RecursiveAdd(Node *p)
{
    if(p== nullptr)
        return 0;
    return RecursiveAdd(p->next)+p->data;
}
int LinkedList::RecursiveMax(Node *p)
{
    int x;
    if(p== nullptr)
        return INT32_MIN;
    x=RecursiveMax(p->next);
    return x>p->data? x : p->data;
}
int LinkedList::RecursiveMin(Node *p)
{
    int x;
    if(p== nullptr)
        return INT32_MAX;
    x=RecursiveMax(p->next);
    return x>p->data? p->data : x;
}
Node* RecursiveSearch(Node *p,int key)//it just works like normal function no need for declaration in class
{                                       // Node returned here just works like datatype
    if(p== nullptr)
        return nullptr;
    if(key==p->data)
        return p;
    return RecursiveSearch(p->next,key);
}
Node * LinkedList::ImprovedSearching(Node *p, int key) {
    Node* q= nullptr;
    while(p)
    {
        if(key==p->data)
        {
            if(q) {
                q->next = p->next;
                p->next = head;
                head = p;
            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return nullptr;
}
bool LinkedList::isSorted(Node *p)
{
	int x=INT32_MIN;
	while(p)
	{
		if(p->data<x)
			return false;
		x=p->data;
		p=p->next;
	}
	return true;
}

//Note: using recursion every time is not feasible just showing the another way of doing the same thing
int main() {
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    cout<<"\nRecursive Display";
    l.RecursiveDisplay(l.head);
    cout<<"\nRecursive length :"<<l.RecursiveLength(l.head);
    cout<<"\n RecursiveAdd :"<<l.RecursiveAdd(l.head);
    cout<<"\n RecursiveMax :"<<l.RecursiveMax(l.head);
    cout<<"\n RecursiveMin :"<<l.RecursiveMin(l.head);
    cout<<"\n RecursiveSearch :"<<RecursiveSearch(l.head,3)->data<<" found";
    cout<<"\n Searching :"<<l.ImprovedSearching(l.head,1)->data<<" found\n";
    l.RecursiveDisplay(l.head);
    if(l.isSorted(l.head))
        cout<<" yes LL is Sorted";
    return 0;
}
