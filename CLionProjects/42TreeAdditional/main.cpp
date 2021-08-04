#include<iostream>
#include<stack>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};
node *root=nullptr;//global

class bt:private node{
public:

    void create();
    ~bt();
    void insert(node*,node*);
    static void iterativePreorder(node*);
    static void iterativeInorder(node*);
    static void postOrder(node*);
    static int countNode(node*);
    static int countTwoNode(node*);
    static int sum(node*);
    static int countOneNode(node*);
    static int countLeafNode(node*);
    void DestroyTree(node *t);
};

void bt::create(){
    node* temp=new node;
    cout<<"Enter data";
    cin>>temp->data;
    temp->right=nullptr;
    temp->left=nullptr;
    if(root==nullptr)
    {
        root=temp;
    }
    else{
        insert(temp,root);
    }
}
void bt::insert(node* temp,node* p)
{
    int ch;
    cout<<"\nEnter 0: left  1: right : ";
    cin>>ch;
    switch(ch)
    {
        case 0: if(p->left==nullptr)
                p->left=temp;
                else
                insert(temp,p->left);
                break;
        case 1: if(p->right==nullptr)
                p->right=temp;
                else
                insert(temp,p->right);
                break;
        default: cout<<"Invalid Entry...";
    }
}
bt::~bt(){
    DestroyTree(root);
}
void bt::iterativePreorder(node* t)
{
    stack<node*>stk;
    while(t!= nullptr||!stk.empty())
    {
        if(t)
        {
            cout<<t->data;
            stk.push(t);
            t=t->left;
        }
        else{
            t=stk.top();
            stk.pop();
            t=t->right;
        }
    }
}
void bt::iterativeInorder(node* t)
{
    stack<node*>stk;
    while(t!= nullptr||!stk.empty())
    {
        if(t)
        {
            stk.push(t);
            t=t->left;
        }
        else{
            t=stk.top();
            stk.pop();
            cout<<t->data;
            t=t->right;
        }
    }
}
void bt::postOrder(node* t) {
    stack<long int>stk;
    long int temp;
    while(t!= nullptr||!stk.empty())
    {
        if(t)
        {
            stk.emplace((long int)t);
            t=t->left;          // this went all the way to the left
        }
        else{
            temp=stk.top();
            stk.pop();
            if(temp>0)              // if positive then we are at inorder's place else postorder's place
            {
                stk.emplace(-temp);
                t=((node*)temp)->right;         // this is going all the way to the right
            }
            else{
                cout<<((node*)(-1*temp))->data;     // if negative make it +ve and print it's value
                t= nullptr;             // this tells that we have visited both the nodes
            }
        }
    }
}
int bt::countNode(node* t) {
    int x,y;
    if(t)
    {
        x=countNode(t->left);
        y=countNode(t->right);
        return x+y+1;
    }
    return 0;
}
int bt::countTwoNode(node * t) {                // Nodes having degree two
    int x,y;
    if(t)
    {
        x=countTwoNode(t->left);
        y=countTwoNode(t->right);
        if(t->left&&t->right)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int bt::sum(node *t) {
    int x,y;
    if(t)
    {
        x=sum(t->left);
        y=sum(t->right);
        return x+y+t->data;
    }
    return 0;
}
int bt::countLeafNode(node *t)
{
    int x,y;
    if(t)
    {
        x=countLeafNode(t->left);
        y=countLeafNode(t->right);
        if(t->left== nullptr && t->right== nullptr)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
int bt::countOneNode(node *t)           //Nodes having degree one
{
    int x,y;
    if(t)
    {
        x=countOneNode(t->left);
        y=countOneNode(t->right);
        if(t->left!=nullptr ^ t->right!= nullptr)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
void bt::DestroyTree(node *t) {
    if (t != nullptr){
        DestroyTree(t->left);
        DestroyTree(t->right);
        delete t;
    }
}
int main()
{
    int ch;
    bt obj;
    for(;;)
    {
        cout<<"\n1.insert";
        cout<<"\n2.iterativeInorder";
        cout<<"\n3.iterativePreorder";
        cout<<"\n4.postOrder";
        cout<<"\n5.countNode";
        cout<<"\n6.countTwoNode";
        cout<<"\n7.Sum";
        cout<<"\n8.countOneNode";
        cout<<"\n9.countLeafNode";
        cout<<"\n10.Exit";
        cout<<"\n\nEnter choice";
        cin>>ch;

        switch(ch)
        {
            case 1:obj.create();
                break;
            case 2:obj.iterativeInorder(root);
                break;
            case 3:obj.iterativePreorder(root);
                break;
            case 4:obj.postOrder(root);
                break;
            case 5: cout<<"Total Nodes:"<<obj.countNode(root);
                break;
            case 6: cout<<"Total Two Nodes:"<<obj.countTwoNode(root);
                break;
            case 7: cout<<"Total/Sum:"<<obj.sum(root);
                break;
            case 8: cout<<"Total One Nodes:"<<obj.countOneNode(root);
                break;
            case 9: cout<<"Total leaf Nodes:"<<obj.countLeafNode(root);
                break;
            case 10:exit(0);            // exit with return 0.....No need for extra return 0 at last
            default: cout<<"\nInvalid choice";
        }
    }
}