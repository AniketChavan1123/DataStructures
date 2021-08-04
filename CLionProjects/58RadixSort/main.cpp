#include <iostream>
#include <cmath>

using namespace std;

template <class T>
void Print(T& vec, int n,const string &s){
//    You're just passing pointers around, no copying, no moving, everyone's happy.
//    function takes a const& because it doesn't store the string. It simply uses it.
//    storing is more expensive than passing reference
//    f(const string) takes a string value, which means f is given a copy of the original string. ...
//    In f(const string& s) instead the string is not copied but you pass a reference to it.
//    string& s if passed  then s can be changed
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Max(const int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

//Linked List Node
class Node
{
public:
    int value;
    Node* next;
};
int countDigits(int x)
{
    int count=0;
    while(x!=0){
        x=x/10;
        count++;
    }
    return count;   //total passes to be performed
}
void initializeBins(Node** p,int n)
{
    for(int i=0;i<n;i++){
        p[i]= nullptr;
    }
}
void Insert(Node** ptrBins,int value,int idx)
{
    Node* temp=new Node;
    temp->value=value;
    temp->next= nullptr;

    if(ptrBins[idx]==nullptr){
        ptrBins[idx]=temp;  // ptrBins[idx] is head ptr
    }
    else{
        Node* p=ptrBins[idx];
        while(p->next!= nullptr){
            p=p->next;
        }
        p->next=temp;
    }
}
int Delete(Node** ptrBins,int idx)
{
    Node* p=ptrBins[idx];
    ptrBins[idx]=ptrBins[idx]->next;
    int x=p->value;
    delete p;
    return x;
}
int getBinIndex(int x,int idx)
{
    return (int)(x/pow(10,idx))%10;
}

void RadixSort(int A[],int n)
{
    int max=Max(A,n);
    int nPass= countDigits(max);

    //create Bins Array
    Node** bins=new Node*[10];

    //initialize bins array with nullptr
    initializeBins(bins,10);

    //update bins and A for nPass times
    for(int pass=0;pass<nPass;pass++){

        //update bins bases on A values
        for(int i=0;i<n;i++){
            int binIdx= getBinIndex(A[i],pass);
            Insert(bins,A[i],binIdx);
        }
        //update A with Sorted elements from bin
        int i=0;
        int j=0;
        while(i<10){
            while(bins[i]!= nullptr){
                A[j++]= Delete(bins,i);
            }
            i++;
        }
        //initialize bins with nullptr again
        initializeBins(bins,10);
    }
    //Delete heap memory
    delete[] bins;
}
int main() {
    int A[]={237,146,259,348,152,163,235,48,36,62};
    int n= sizeof(A)/ sizeof(A[0]);
    Print(A,n,"\t\tA");
    RadixSort(A,n);
    Print(A,n,"Sorted A");
    return 0;
}
