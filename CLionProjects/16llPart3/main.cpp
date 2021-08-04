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

    LinkedList(const int A[], int);

    virtual ~LinkedList();

    static void RecursiveDisplay(Node *p);

    static Node * Concatenate(Node *one, Node *two);  // bcz this is not related to particular object
};
void LinkedList::RecursiveDisplay(Node *p) {
    if (p != nullptr) {
        cout << p->data<<" ";  // Forward Display
        RecursiveDisplay(p->next);
//        cout << p->data;  // Reverse Display
    }
}
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
Node* LinkedList::Concatenate(Node *one,Node *two)
{
    Node *temp,*thirdHead;
    if(one->data<two->data)         // to decide whose data is small
    {
        thirdHead=temp=one;         // thirdHead becomes head of concatenated ll
        one=one->next;
        temp->next= nullptr;
    }
    else{
        thirdHead=temp=two;
        two=two->next;
        temp->next= nullptr;
    }
    while(one && two)           // connecting 2 ll
    {
        if(one->data<two->data)
        {
            temp->next=one;
            temp=one;
            one=one->next;
            temp->next= nullptr;
        }
        else{
            temp->next=two;
            temp=two;
            two=two->next;
            temp->next= nullptr;
        }
    }
     if(one)   // when any ll finishes then connect other string entirely
     {
        temp->next=one;
     }
     if(two)
     {
         temp->next=two;
     }
    return thirdHead;
}

int main() {
    int A[] = {1,3,5,9,11};
    int B[]={2,4,6,7,13};
    LinkedList l(A, 5);
    LinkedList m(B,5);
    cout<<"ONE : ";
    LinkedList::RecursiveDisplay(l.head);
    cout<<"\n";
    cout<<"TWO : ";
    LinkedList::RecursiveDisplay(m.head);
    cout<<"\nConcatenate : ";
    Node *third=LinkedList::Concatenate(l.head,m.head);
    LinkedList::RecursiveDisplay(third);
    return 0;
}