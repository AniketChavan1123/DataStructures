#include <iostream>
using namespace  std;
class Node{
public:
    int col;
    int data;
    Node *next;
};
class sparse{
private:
    Node *head;
    Node *tail;
    Node **B;       // B is a pointer that points to the array of Node pointers
    // like this is (int*) integer pointer holds address where int value is defined
public:
    sparse(int m,int A[][6]);
    ~sparse();
    void display();
    void matrix();
};
sparse::sparse(int m, int (*A)[6]) {		// A is pointer to 5 Array and Each array has 6 integers
    B=new Node* [5]; //Dynamic array of pointer having size 5 using new is created as
    for(int i=0;i<m;i++)
    {
        head= nullptr;
        tail= nullptr;
        for (int j = 0; j < 6; ++j) {
            if(A[i][j]!=0)
            {
                if(head== nullptr)
                {
                    head=new Node;
                    head->data=A[i][j];
                    head->col=j;
                    head->next= nullptr;
                    tail=head;
                }
                else{
                    Node *temp=new Node;
                    temp->data=A[i][j];
                    temp->next= nullptr;
                    temp->col=j;
                    tail->next=temp;
                    tail=temp;
                }
            }
        }
        B[i]=head;      // B is pointer to array of pointers and B[i] is also a pointer
                        // so it can hold head Pointer as both have same type
    }
}
sparse::~sparse() {
    Node *temp;
    for(int i=0;i<5;i++)         // range bases loop as B is 1D array
    {
        Node *p=B[i];
        while(p) {
            temp = p;
            cout << " deleting " << temp->data << endl;
                p = p->next;
            delete temp;            // with this ,we made all B[i] null
        }
    }
    delete [] B;               // we deleted whole array of pointer at last
    delete head;                // so we used delete array Operator
    delete tail;
}
void sparse::display()
{
    for(int i=0;i<5;i++)         // range bases loop as B is 1D array
    {
        Node *p=B[i];
        while(p)
        {
            cout<<"("<<p->col<<","<<p->data<<")";
            if(p->next)
            {
                cout<<"->";
            }
            p=p->next;
        }
        cout<<endl;
    }
}
void sparse::matrix()
{
    for(int j=0;j<5;j++)
    {Node *p=B[j];
        for(int i=0;i<6;i++)
        {
            if(p && p->col==i)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


int main() {
    int A[5][6]={{0,0,0,0,8,0},{0,0,0,7,0,0},{5,0,0,0,4,0},{0,0,0,0,0,3},{6,0,0,4,0,0}};
    sparse yes(5,A);
    yes.display();
    yes.matrix();
    return 0;
}

//// Important tip
// **B is used to make 2D arrays like this
//int** matrix = new int*[5];
//for (int i = 0; i < 5; ++i) {
//matrix[i] = new int[5];       which each matrix[i] pointer again holds array of 5 int->
//                              but we used this pointer to store head Node of our Linked list
//for (int j = 0; j < 5; ++j) {
//matrix[i][j] = i*5 + j;
//}
//}

//int a[5] a is an array of 5 int.
//int (*a)[5] a is a pointer to an array of 5 int.
//int a[5][4] a is an array of 5 array of 4 int.
//int *a[5] a is an array of 5 int pointers.

//// How to free the matrix
////Free each sub-array
//for(int i = 0; i < 5; ++i) {
//delete[] matrix[i]; here matrix[i] is pointer to an array so we used delete[](delete array operator)
//              but in our case B[i] was pointing to single Node which further Points to another Node
//}

////Free the array of pointers
//delete[] matrix;

