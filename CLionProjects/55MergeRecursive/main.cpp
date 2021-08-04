#include <iostream>

using namespace std;

template <class T>
void Print(T& vec,int n,const string& s)
{
    cout<<s<<":["<<flush;
    for(int i=0;i<n;i++)
    {
        cout<<vec[i]<<flush;
        if(i<n-1)
        {
            cout<<","<<flush;
        }
    }cout<<"]"<<endl;
}

void Merge(int A[],int low,int mid,int high)
{
    int i =low;
    int j=mid+1;
    int k=low;
    int B[high+1];
    while(i<=mid && j<=high){
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }else{
            B[k++]=A[j++];
        }
    }
    while(i<=mid){      //copying remaining element
        B[k++]=A[i++];
    }
    while(j<=high){
        B[k++]=A[j++];
    }
    for(i=low;i<=high;i++){
        A[i]=B[i];
    }
}
void recursiveMergeSort(int A[],int low,int high)
{
    if(low<high)
    {
        //calculate mid point
        int mid=low+(high-low)/2;

        // sort sub lists
        recursiveMergeSort(A,low,mid);
        recursiveMergeSort(A,mid+1,high);

        // Merge Sorted Sub lists
        Merge(A,low,mid,high);
    }
}
int main() {
    int A[]={2,5,8,12,3,6,7,10,4};
    int n= sizeof(A)/ sizeof(A[0]);
    Print(A,n,"\t\tA");
    recursiveMergeSort(A,0,n-1);
    Print(A,n,"Sorted A");
    return 0;
}
