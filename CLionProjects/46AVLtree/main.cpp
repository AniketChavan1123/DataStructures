#include <iostream>
using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};
class AVL{
public:
    Node* root;
    AVL(){
        root= nullptr;
    }
    //HELPER method  for inserting
    static int NodeHeight(Node* p);
    static int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    //Insert
    Node* rInsert(Node* p,int key);

    //traversal
    void inorder(Node* p);
    void inorder(){
        inorder(root);
    }
    Node* getRoot() const{
        return root;
    }

    static Node *inPre(Node *p);

    static Node *inSucc(Node *p);

    Node *Delete(Node *p, int key);
};
int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;
    hl=(p && p->lchild) ? p->lchild->height : 0;
    hr=(p && p->rchild) ? p->rchild->height : 0;

    return (hl>hr) ? hl+1 : hr+1;       // always longest is considered
}
int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;
    hl=(p && p->lchild) ? p->lchild->height : 0;
    hr=(p && p->rchild) ? p->rchild->height : 0;

    return hl-hr;
}
Node* AVL::LLRotation(Node *p) {
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    //update height
    p->height= NodeHeight(p);
    pl->height= NodeHeight(p);

    //update root
    if(root==p)
    {
        root=pl;
    }
    return pl;
}
Node* AVL::RRRotation(Node *p) {
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    //update height
    p->height= NodeHeight(p);
    pr->height= NodeHeight(p);

    //update root
    if(root==p)
    {
        root=pr;
    }
    return pr;
}
Node* AVL::LRRotation(Node *p) {
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->rchild=p;
    plr->lchild=pl;

    //update height
    pl->height= NodeHeight(pl);
    p->height= NodeHeight(p);
    plr->height= NodeHeight(plr);

    //update root
    if(p==root)
    {
        root=plr;
    }
    return plr;
}
Node* AVL::RLRotation(Node *p) {
    Node* pr=p->rchild;
    Node* prl=pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    //update height
    pr->height= NodeHeight(pr);
    p->height= NodeHeight(p);
    prl->height= NodeHeight(prl);
    //update root
    if(p==root)
    {
        root=prl;
    }
    return prl;
}
Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if(p== nullptr)
    {
        t=new Node;
        t->data=key;
        t->lchild= nullptr;
        t->rchild= nullptr;
        t->height=1;
        //starting height from 1 instead of 0
        return t;
    }
    if(key<p->data)
    {
        p->lchild= rInsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild= rInsert(p->rchild,key);
    }
    //update height
    p->height= NodeHeight(p);

    //balance factor
    if(BalanceFactor(p)==2&& BalanceFactor(p->lchild)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2&& BalanceFactor(p->lchild)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2&& BalanceFactor(p->rchild)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2&& BalanceFactor(p->rchild)==1){
        return RLRotation(p);
    }
    return p;
}
void AVL::inorder(Node *p) {
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" "<<flush;
        inorder(p->rchild);
    }
}
// Deletion from AVL tree
Node* AVL::inPre(Node* p)
{
    while(p && p->rchild!= nullptr)
    {
        p=p->rchild;
    }
    return p;
}
Node* AVL::inSucc(Node* p)
{
    while(p && p->lchild!= nullptr)
    {
        p=p->lchild;
    }
    return p;
}
Node* AVL::Delete(Node* p, int key)
{
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
        p->lchild= Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild= Delete(p->rchild,key);
    }
    else{
        Node* q;
        if(NodeHeight(p->lchild)> NodeHeight(p->rchild))
        {
            q= inPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q= inSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    //Update height
    p->height= NodeHeight(p);
    //Balance factor and rotation

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    {
        // L1 Rotation
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    {
        // L-1 Rotation
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
    {
        //R-1 Rotation
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
    {
        //R1 Rotation
        return RLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
    {
        //L0 Rotation
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
    {
        //R0 Rotation
        return RRRotation(p);
    }
    return p;
}
int main() {
    // LR Rotation
    AVL tlr;
    tlr.root=tlr.rInsert(tlr.root,50);
    tlr.root=tlr.rInsert(tlr.root,10);
    tlr.root=tlr.rInsert(tlr.root,20);

    cout<<"\ninorder LR:";
    tlr.inorder();
    cout<<endl;
    cout<<tlr.root->data<<endl;
    
    //RL Rotation
    AVL trl;
    trl.root=trl.rInsert(trl.root,20);
    trl.root=trl.rInsert(trl.root,50);
    trl.root=trl.rInsert(trl.root,30);

    cout<<"\ninorder RL:";
    trl.inorder();
    cout<<endl;
    cout<<trl.root->data<<endl;

    //deletion
    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.inorder();
    cout << endl;

    tree.Delete(tree.root, 28);

    tree.inorder();
    cout << endl;
    return 0;
}
