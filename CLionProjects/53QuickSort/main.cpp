#include <iostream>

using namespace std;

template<class T>
void Print(T& vec,int n,const string& s)
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
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
//first element is pivot
int partition(int A[],int low,int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;

    while(true){
        while(i<=j && A[i]<=pivot){
            i++;
        }
        while(A[j]>=pivot && j>=i){
            j--;
        }
        if(j<i){
            break;
        }else{
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[low],&A[j]);
    return j;
}

void quickSort(int A[],int low,int high)
{
    if(low < high){
        int p= partition(A,low,high);
        quickSort(A,low,p-1);
        quickSort(A,p+1,high);
    }
}
int main() {

    int C[]={11,13,7,12,16,9,9,24,5,10,3};
    int n= sizeof(C)/ sizeof(C[0]);
    Print(C,n,"\t\tC");
    quickSort(C,0,n-1);
    Print(C,n,"Sorted C");

    return 0;
}
