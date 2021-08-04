#include <iostream>
#include <cmath>
using namespace std;
class Node{
public:
    int coeff;
    int exp;
    Node *next;
}*head= nullptr;

void create(){
    Node *tail;
    int num;
    cout<<"Enter number of terms";
    cin>>num;
    cout<<"\nEnter each term with coeff and exponent: ";
    for(int i=0;i<num;i++)
    {
        Node *temp=new Node;
        cin>>temp->coeff;
        cin>>temp->exp;
        temp->next=nullptr;

        if(!head)
        {
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
}
void display(Node *p)
{
    while(p){
        cout<<"("<<p->coeff<<"X"<<p->exp<<")";
        if(p->next)
        {
            cout<<" + ";
        }
        p=p->next;

    }
    cout<<endl;
}
long Eval(Node *p,int x)
{
    long val=0;
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
int main() {
    create();
    display(head);
    cout<<"Evaluation:"<<Eval(head,2);
    return 0;
}
