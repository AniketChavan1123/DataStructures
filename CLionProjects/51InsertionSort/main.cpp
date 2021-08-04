#include <iostream>

using namespace std;
template<class T>
void Print(T& vec,int n,const string &s)
{
    cout<<s<<":["<<flush;
    for(int i=0;i<n;i++)
    {
        cout<<vec[i]<<flush;
        if(i<n-1){
            cout<<","<<flush;
        }
    }
    cout<<"]"<<endl;
}
void insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main() {
    int A[]={19,17,15,13,11,9,7,5,3,1};
    Print(A, sizeof(A)/ sizeof(A[0]),"\tA");
    insertionSort(A, sizeof(A)/ sizeof(A[0]));
    Print(A, sizeof(A)/ sizeof(A[0]),"Sorted A");
    return 0;
}
