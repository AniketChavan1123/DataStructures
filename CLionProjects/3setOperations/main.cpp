#include <iostream>
using namespace std;

class Array{
public:
    int *A;
    int *B;
    int *C;
    int aLength,bLength,cLength;
};

void Uunion(Array *object)
{
    for(int i=0;i<object->aLength;i++)
        object->C[i]=object->A[i];
    object->cLength=object->aLength;
    for(int i=0;i<object->bLength;i++)
    {
        bool ans=true;
        for(int j=0;j<object->cLength;j++)
        {
            if(object->B[i]==object->C[j])
                ans=false;
        }
        if(ans)
        {
            object->C[object->cLength++]=object->B[i];      // first assign then increment
        }
    }
}
void Sunion(Array *object)
{
    int i=0,j=0,k=0;
    while(i<object->aLength && j<object->bLength)
    {
        if(object->A[i]<object->B[j])
        {
            object->C[k++]=object->A[i];
            i++;
        }
        else if(object->A[i]>object->B[j])
        {
            object->C[k++]=object->B[j];
            j++;
        }
        else{
            object->C[k++]=object->A[i++];
            j++;
        }
    }
    for(;i<object->aLength;)
    {
        object->C[k++]=object->A[i++];
    }
    for(;j<object->bLength;)
    {
        object->C[k++]=object->B[j++];
    }
    object->cLength=k;
}
void Uintersection(Array *object)
{
    int k=0;
    for(int i=0;i<object->aLength;i++)
    {
        int j=0;
        while(object->A[i]!=object->B[j] && j<object->bLength){++j;}        //comparing until we get A[i]=B[i]
        if(j<object->bLength)                   // j<object->bLength means we found the element before j limit Exceeds
        {
            object->C[k++]=object->A[i];
        }
    }
    object->cLength=k;
}
void Sintersection(Array *object)
{
    int i=0,j=0,k=0;
    while(i<object->aLength && j<object->bLength)
    {
        if(object->A[i]<object->B[j])
        {
            i++;
        }
        else if(object->A[i]>object->B[j])
        {
            j++;
        }
        else{
            object->C[k++]=object->A[i++];
            j++;
        }
        object->cLength=k;
    }
    for(;i<object->aLength;)
    {
        object->C[k++]=object->A[i++];
    }
    for(;j<object->bLength;)
    {
        object->C[k++]=object->B[j++];
    }
}
void UDifference(Array *object)
{
    int k=0;
    for(int i=0;i<object->aLength;i++)
    {
        int j=0;
        while(object->A[i]!=object->B[j] && j<object->bLength){++j;}        //comparing until we get A[i]=B[i]
        if(j==object->bLength)                   // j==object->bLength means we found the element which are not in B.
        {
            object->C[k++]=object->A[i];
        }
    }
    object->cLength=k;
}
void SDifference(Array *object)
{
    int i=0,j=0,k=0;
    while(i<object->aLength && j<object->bLength)
    {
        if(object->A[i]<object->B[j]){                  // don't ever put increment in iff condition
            object->C[k++]=object->A[i++];              //bcz even if iff() fails increment will happen
        }
        else if(object->A[i]==object->B[j]){            // don't play increment stunts everywhere use wisely
            i++;j++;                                    // i did object->A[i++] which gave me wrong ans
        }
        else j++;
    }
    for(;i<object->bLength;)
    {
        object->C[k++]=object->A[i++];
    }
    object->cLength=k;
}
int main() {

    class Array object{};
    object.A=new int[5];                    //sizeof(*object.A)=4 as int is pointing to first element of an array

    object.B=new int[5];                    //sizeof(object.A)=8 as it is pointer which takes 8 bytes
    object.C=new int[15];
    object.aLength=object.bLength=5;
    cout<<"Enter 2 Array of size 5";
    for(int i=0;i<object.aLength;i++)       //algorithm may vary but logic will be same
    {
        cin>>object.A[i];                   //put 3 5 10 4 6
        cin>>object.B[i];                   //put 12 4 7 2 5
    }
//  Sunion(&object);                           // change S with U to use another;
//  Uintersection(&object);                    // comment Sunion to use intersection
    UDifference(&object);
    for(int i=0;i<object.cLength;i++)
    {
        cout<<object.C[i]<<" ";
    }

    return 0;
}
