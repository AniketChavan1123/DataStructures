#include <iostream>
using namespace std;
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
class BST{
private:
    Node* root;
public:
    BST(){
        root= nullptr;
    }
    Node* getRoot(){
        return root;
    }
    void insert(int key);
    void inorder(Node* p);
    Node* Search(int key);

    Node *Delete(Node *p, int key);

    int Height(Node *p);

    static Node *Inpre(Node *p);

    static Node *Insucc(Node *p);

    void preorder(Node *p);
};
void BST::insert(int key) {
    Node* t=root;
    Node* p;
    Node* r;

    //root is Empty
    if(root==nullptr)
    {
        p=new Node;
        p->data=key;
        p->lchild= nullptr;
        p->rchild= nullptr;
        root=p;
        return;
    }
    while(t!= nullptr)
    {
        r=t;    // when t points at null r points at insert location
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else return;
    }
    p=new Node;
    p->data=key;
    p->rchild= nullptr;
    p->lchild= nullptr;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}
void BST::preorder(Node *p) {
    if(p)
    {
        cout<<p->data<<" ";
        inorder(p->lchild);
        inorder(p->rchild);
    }
}
void BST::inorder(Node *p) {
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
Node* BST::Search(int key) {
    Node *t=root;
    while(t!= nullptr)
    {
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else if(key==t->data){
            return t;
        }
    }
    return nullptr;
}
Node* BST::Delete(Node* p, int key)
{
    Node* q;
    if(p== nullptr)
    {
        return nullptr;
    }
    if(p->lchild== nullptr && p->rchild== nullptr)
    {
        if(p==root)
        {
            root= nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key<p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(p->lchild== nullptr)
        {
            Node* temp=p;
            p=p->rchild;
            delete temp;
        }
        else if(p->rchild==nullptr)
        {
            Node* temp=p;
            p=p->lchild;
            delete temp;
        }
        else if(Height(p->lchild)<Height(p->rchild))
        {
            q=Inpre(p->lchild);     // then go to right until nullptr
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insucc(p->rchild);     // then go to right until nullptr
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int BST::Height(Node* p)
{
    int x;
    int y;
    if(p==nullptr)
    {
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
Node* BST::Inpre(Node* p)
{
    while(p && p->rchild!= nullptr)
    {
        p=p->rchild;
    }return p;
}
Node* BST::Insucc(Node* p)
{
    while(p && p->lchild!= nullptr)
    {
        p=p->lchild;
    }return p;
}
int main() {
    BST bst;
    int A[]={9,5,3,8,6,15,12,20,16,36,33,34,35,41};
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
    {
        bst.insert(A[i]);
    }
    bst.inorder(bst.getRoot());
    cout<<"\n finding 36 ";
    cout<<"\n"<<bst.Search(36)->data<<" found";
    cout<<"\ndeleting 36 ";
    bst.Delete(bst.getRoot(),36);
    cout<<"\n";
    bst.preorder(bst.getRoot());
    if(bst.Search(36))
        cout<<"\n36 found";
    else
        cout<<"\n36 not found";
    cout<<"\ndeleting 20 ";
    bst.Delete(bst.getRoot(),20);
    cout<<endl;
    bst.inorder(bst.getRoot());

    return 0;
}
