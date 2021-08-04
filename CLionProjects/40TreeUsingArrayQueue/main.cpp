#include <iostream>
using namespace std;
class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;           // to store address of Nodes of tree
public:
    explicit Queue(int size);
    ~Queue();
    bool isFull() const;
    bool isEmpty() const;
    void enqueue(Node *x);
    Node* dequeue();
};
Queue::Queue(int size) {
    this->size=size;
    front=-1;
    rear=-1;
    Q=new Node*[size];
}
Queue::~Queue() {
    delete[] Q;
}
bool Queue::isEmpty() const{
    if(front==rear)
    {
        return true;
    }
    return false;
}
bool Queue::isFull() const{
    if(rear==size-1)
    {
        return true;
    }return false;
}

void Queue::enqueue(Node *x)
{
    if(isFull())
    {
        cout<<"Queue Overflow";
    }else{
        rear++;
        Q[rear]=x;
    }
}
Node* Queue::dequeue() {
    Node *x= nullptr;
    if(isEmpty())
    {
        cout<<"Queue Underflow";
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}


class Tree{
private:
    Node *root;
public:
    Tree(){
        root= nullptr;
    }
    void createTree();
    void preorder()
    {
        preorder(root);
    }
    void preorder(Node* p);
    void postorder(){
        postorder(root);
    }
    void postorder(Node* p);
    void inorder()
    {
        inorder(root);
    }
    void inorder(Node* p);

    void levelorder(){
        levelorder(root);
    }
    void levelorder(Node* p);
    Node* getroot(){
        return root;
    }
    virtual ~Tree();
    void deletePostOrder(Node *p);
};
void Tree::createTree()
{
    Node* p;
    Node* t;
    int x;
    Queue q(7);
    root=new Node;
    cout<<"Enter root value:"<<flush;
    cin>>x;
    root->data=x;
    root->lchild= nullptr;
    root->rchild= nullptr;
    q.enqueue(root);

    while(!q.isFull())
    {
        p=q.dequeue();
        cout<<"Enter leftchild value of "<<p->data<<" :"<<flush;
        cin>>x;
        if(x!=-1)       // -1 means we don't want to put it there
        {
            t=new Node;
            t->data=x;
            t->lchild= nullptr;
            t->rchild= nullptr;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter righttchild value of "<<p->data<<" :"<<flush;
        cin>>x;
        if(x!=-1)       // -1 means we don't want to put it there
        {
            t=new Node;
            t->data=x;
            t->lchild= nullptr;
            t->rchild= nullptr;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::preorder(Node *p) {
    if(p)
    {
        cout<<p->data<<flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }

}
void Tree::inorder(Node* p) {
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<flush;
        inorder(p->rchild);
    }

}
void Tree::postorder(Node* p) {
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<flush;
    }
}
void Tree::levelorder(Node* p) {
    Queue q(7);
    cout<<root->data<<","<<flush;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p=q.dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data<<","<<flush;
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<","<<flush;
            q.enqueue(p->rchild);
        }
    }

}
void Tree::deletePostOrder(Node* p) {
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        delete p;
    }
}
Tree::~Tree() {
    deletePostOrder(root);
}

int main() {
    Tree t;
    t.createTree();
    cout<<"preorder: "<<flush;
    t.preorder(t.getroot());
    cout<<endl;
    t.inorder();
    cout<<endl;
    t.postorder();
    cout<<endl;
    t.levelorder();
    cout<<endl;
    return 0;
}
/*//Virtual destructors are useful when you might potentially delete an instance of a derived
 class through a pointer to base class:

class Base
{
    // some virtual methods
};

class Derived : public Base
{
    ~Derived()
    {
        // Do some important cleanup
    }
};
Here, you'll notice that I didn't declare Base's destructor to be virtual.
 Now, let's have a look at the following snippet:

Base *b = new Derived();
// use b
delete b; // Here's the problem!
Since Base's destructor is not virtual and b is a Base* pointing to a Derived object,
 delete b has undefined behaviour:

[In delete b], if the static type of the object to be deleted is different from its dynamic type,
 the static type shall be a base class of the dynamic type of the object to be deleted
 and the static type shall have a virtual destructor or the behavior is undefined.

In most implementations, the call to the destructor will be resolved like any non-virtual code,
 meaning that the destructor of the base class will be called but not the one of the derived class,
 resulting in a resources leak.

To sum up, always make base classes' destructors virtual when they're meant to be manipulated
 polymorphically.

If you want to prevent the deletion of an instance through a base class pointer,
 you can make the base class destructor protected and nonvirtual; by doing so,
 the compiler won't let you call delete on a base class pointer.
 */