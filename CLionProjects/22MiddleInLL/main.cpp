// find the middle element in linked list----explanation in notebook
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
class Node{
public:
    int data;
    Node *next;
}//variable defined here are also global
;
Node *head=new Node;        // head is global variable now but global variables are bad
void create(const int A[],int n)
{
    Node *temp;
    Node *tail;
    head->data=A[0];
    head->next= nullptr;
    tail=head;
    for(int i=1;i<n;i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next= nullptr;
        tail->next=temp;
        tail=temp;
    }
}
void methodOne(Node *p)
{
    Node *q=p;      // p and q are at same position
    while(q)
    {
        q=q->next;  // either it will go to next Node or it will become nullptr
        if(q)   // if q!=null then proceed
        {
            q=q->next;  // q may become null here
        }
        if(q)
        {
            p=p->next;      // if q!=null increment p;
        }
    }
    cout<<"Middle Element :"<<p->data;
}
void methodTwo(Node *p)
{
    stack<Node*>S;          // stack to store address of Nodes
    while(p){
        S.push(p);
        p=p->next;
    }
    int length=S.size();
    int popLength=(int)(floor(length/2.0));
    while(popLength)        // until it becomes 0
    {
        S.pop();
        popLength--;
    }
    cout<<"\nmiddle Element :"<<S.top()->data<<endl;
}

int main() {
    int A[]={1,3,5,7,9,11,13,15,17,19,21};
    create(A, sizeof(A)/ sizeof(A[0]));
    cout<<endl;
    methodOne(head);
    methodTwo(head);
    return 0;
}
