#include <iostream>
#include<stack>
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
    void createFromPreorder(const int pre[],int n);
    void inorder(Node* p);
    Node *getRoot() const;
};
void BST::createFromPreorder(const int *pre, int n) {
    //create root node
    int i=0;
    root=new Node;
    root->data=pre[i++];
    root->lchild= nullptr;
    root->rchild= nullptr;

    //iterative steps
    Node* t;
    Node* p=root;
    stack<Node*>stk;

    // last element entered will be P
    while(i<n){
        //left child case
        if(pre[i]<p->data)
        {
            t=new Node;
            t->data=pre[i++];
            t->lchild= nullptr;
            t->rchild= nullptr;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else if(pre[i]>p->data && pre[i]<(stk.empty()? 32767:stk.top()->data))
        {
            t=new Node;
            t->data=pre[i++];
            t->lchild=t->rchild= nullptr;
            p->rchild=t;
            p=t;
        }
        else{
            p=stk.top();
            stk.pop();
        }
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
Node *BST::getRoot() const {
    return root;
}

int main() {
    //BST from preorder Traversal
    cout<<"BST from preorder: "<<flush;
    //problem: also takes repeated value but preorder really doesn't consist repeated value
    int pre[]={30,20,10,15,25,40,39,50,45,57};
    int n=sizeof(pre)/sizeof(pre[0]);
    BST b;
    b.createFromPreorder(pre,n);
    b.inorder(b.getRoot());
    cout<<endl;
    return 0;
}
