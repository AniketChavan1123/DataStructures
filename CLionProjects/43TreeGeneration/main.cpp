#include <iostream>
#include <stack>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    explicit Node(int);
};

Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Tree{
private:
    Node* root;
public:
    Tree();
    void assignRoot(Node*);
    ~Tree();
    static void postorder(Node*);
    void destroyTree(Node*);
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
};

Tree::Tree() {
    root = nullptr;
}
void Tree::assignRoot(Node* p) {
    root=p;
}

Tree::~Tree() {
    destroyTree(root);
}
void Tree::destroyTree(Node* p)
{
    if(p)
    {
        destroyTree(p->lchild);
        destroyTree(p->rchild);
        delete p;
    }
}


void Tree::postorder(Node *p) {
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data;
    }
}

int searchInorder(const int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    // Reference: https://algorithms.tutorialhorizon.com/make-a-binary-tree-from-given-inorder-and-preorder-traveral/
    static int preIndex = 0;

    if (inStart > inEnd){
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd){
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);

    return node;
}


int main() {
    Tree bt;

    int preorder[] = {8, 7, 6, 5, 4, 9, 3};
    int inorder[] = {7, 8, 4, 5, 6, 3, 9};


    Node* T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    bt.assignRoot(T);
    bt.postorder(T);
    return 0;
}