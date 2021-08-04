#include <iostream>
using namespace std;

 template<class T>
 void Print(T& vec,int n,const string& s)
// when you use 'normal' parameter, you pass the parameter by value and hence creating
// a copy of the parameter you pass. if you are using const reference, you pass it by reference
// and the original data is not copied.
//
//in both cases, the original data cannot be modified from inside the function.
 {

     cout<<s<<":["<<flush;
     for(int i=0;i<n;i++)
     {
         cout<<vec[i]<<flush;
         if(i<n-1){
             cout<<","<<flush;
         }
     }cout<<"]"<<endl;
 }

 void swap(int* x,int* y)   // x & y are int pointer
 {
     int temp= *x;      // accessing value of x
     *x=*y;
     *y=temp;
 }

 void bubbleSort(int A[],int n){
     int flag=0;
     for(int i=0;i<n-1;i++)
     {
         for(int j=0;j<n-1-i;j++)
         {
             if(A[j]>A[j+1])
             {
                 swap(&A[j],&A[j+1]);
                 flag=1;
             }
         }
         if(flag==0)
         {
             return;
         }
     }
 }
int main() {
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n= sizeof(A)/ sizeof(A[0]);
    Print(A,n,"\t\t A");
    bubbleSort(A,n);
    Print(A,n,"Sorted Array");

    return 0;
}
