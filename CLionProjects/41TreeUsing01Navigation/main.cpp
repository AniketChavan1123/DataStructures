#include<iostream>
using namespace std;
#include<queue>

#define INT_MIN -9999
#define INT_MAX  9999
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
    void insert(node*,node*);
    void display(node*);
    void Searchdisplay(node*,int,node*);
    void Searchdelete(node*,int,node*);
    void Searchmodify(node*,int,int,node*);
    void mirror(node*);
    int findheight(node*);
    static void levelorder(node*);
    static bool isBinarySearchTree(node*);
    bool displayCheckBST(node *p, int max,node*);
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

void bt::display(node *p)
{
    //inorder
    if(p!=nullptr)
    {
        display(p->left);         // Read recursion carefully
        cout<<p->data;
        display(p->right);
    }
}

void bt::Searchdisplay(node *p,int key,node* endCondition)
{
    //inorder
    if(endCondition!=nullptr && p!=nullptr)              // why this condition---> so that loop ENDS
    {

        if(p->right!=nullptr&&p->right->data==key)
        {
            cout<<key<<" is right child of "<<p->data;
            endCondition=nullptr;
        }
        else if(p->left!=nullptr&&p->left->data==key)
        {
            cout<<key<<" is left child of "<<p->data;
            endCondition=nullptr;
        }


        Searchdisplay(p->left,key,endCondition);
        Searchdisplay(p->right,key,endCondition);
    }
}


void bt::Searchdelete(node *p,int key,node* endCondition)
{
    //inorder
    if(endCondition!= nullptr&&p!=nullptr)
    {

        if(p->right!=nullptr&&p->right->data==key)
        {
            cout<<key<<" is right child of "<<p->data<<" is deleted";
            endCondition=nullptr;
        }
        else if(p->left!=nullptr&&p->left->data==key)
        {
            cout<<key<<" is left child of "<<p->data<<" is deleted";
            endCondition=nullptr;
        }


        Searchdelete(p->left,key,endCondition);
        Searchdelete(p->right,key,endCondition);
    }
}


void bt::Searchmodify(node *p,int key,int ch,node* endCondition)
{
    //inorder
    if(endCondition!=nullptr && p!= nullptr)
    {

        if(p->right!=nullptr&&p->right->data==key) //why checking condition p->right!=nullptr
        {                              //   |                bcz when it reaches leaf node
            p->right->data=ch;      //-> p->right->data term becomes senseless.bcz leaf node has left,right pointer nullptr
            cout<<key<<" is right child of "<<p->data<<" is Modified to "<<ch;
            endCondition= nullptr;
        }
        else if(p->left!=nullptr&&p->left->data==key)
        {
            p->left->data=ch;
            cout<<key<<" is left child of "<<p->data<<" is Modified to "<<ch;
            endCondition= nullptr;
        }


        Searchmodify(p->left,key,ch,endCondition);
        Searchmodify(p->right,key,ch,endCondition);
    }
}
void bt::mirror(node* p)
{
    if(p!=nullptr)
    {
        node* temp;
        mirror(p->left);
        mirror(p->right);
        temp=p->left;
        p->left=p->right;
        p->right=temp;
    }
}

int bt::findheight(node* p)
{
    if(p==nullptr)
        return -1;

    int leftheight=findheight(p->left);
    int rightheight=findheight(p->right);

    if(leftheight>rightheight)
        return leftheight+1;
    else
        return rightheight+1;
}

void bt::levelorder(node* p)
{
    if(p==nullptr)
        return;
    queue<node*>Q;
    Q.push(p);       //pushing 1st element i.e mandatory

    while(!Q.empty())
    {
        node *current= Q.front();
        cout<<"\t"<<current->data;
        if(current->left!=nullptr)Q.push(current->left);
        if(current->right!=nullptr)Q.push(current->right);
        Q.pop();
    }
}

bool isBSTutil(node* p,int min,int max)
{
    if(p==nullptr)
        return true;

    if(p->data>min && p->data<max && isBSTutil(p->left,min,p->data) && isBSTutil(p->right,p->data,max))
        return true;
    else
        return false;
}

bool bt::isBinarySearchTree(node* p)
{
    return isBSTutil(p,INT_MIN,INT_MAX);
}

bool bt::displayCheckBST(node *p,int max,node* endCondition)
{
    static bool flag=false;
    //inorder
    if(p!=nullptr&&endCondition!=nullptr)
    {
        displayCheckBST(p->left,p->data,endCondition);         // Read recursion carefully
        if(p->data<max)
        {
            flag=!flag;
            if(!flag)
            {
                endCondition= nullptr;      //the second breaking condition really breaks it
            }
        }
        displayCheckBST(p->right,p->data,endCondition);
    }
    return p != nullptr;
}

int main()
{
    int ch,key;
    bt obj;
    for(;;)
    {
        cout<<"\n1.insert";
        cout<<"\n2.search";
        cout<<"\n3.delete";
        cout<<"\n4.modify";
        cout<<"\n5.mirror";
        cout<<"\n6.display";
        cout<<"\n7.findheight";
        cout<<"\n8.LevelOrder";
        cout<<"\n9.isBST";
        cout<<"\n10.isBSTalternate";
        cout<<"\n11.exit";
        cout<<"\n\nEnter choice";
        cin>>ch;

        switch(ch)
        {
            case 1:obj.create();
                break;
            case 2: cout<<"\nEnter key:";
                cin>>key;
                obj.Searchdisplay(root,key,root);
                break;

            case 3: cout<<"\nEnter key:";
                cin>>key;
                obj.Searchdelete(root,key,root);
                break;
            case 4: cout<<"\nEnter key: ";
                cin>>key;
                cout<<"\nEnter key to change with: ";
                cin>>ch;
                obj.Searchmodify(root,key,ch,root);
                break;
            case 5:obj.mirror(root);
                break;

            case 6: obj.display(root);
                break;

            case 7:
                ch=obj.findheight(root);
                cout<<"\nHeight of tree : "<<ch;
                break;

            case 8:obj.levelorder(root);
                break;

            case 9: if(obj.isBinarySearchTree(root))
                    cout<<"\n Yes is a BST";
                    else
                    cout<<"\n Not a BST";
                break;

            case 10:if(obj.displayCheckBST(root,INT_MAX,root))
                    cout<<"\n Yes is a BST";
                    else
                    cout<<"\n Not a BST";
                break;

            case 11:exit(0);

            default: cout<<"\nInvalid choice";

        }
    }
    return 0;
}