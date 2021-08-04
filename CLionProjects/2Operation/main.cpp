#include <iostream>
using namespace std;

class Array
{
public:
    int A[10];
    int length;
};

int get(class Array *obj,int index)
{
    if(index>=0 && index<obj->length)
    {
        return obj->A[index];
    }
    return -1;
}

void set(class Array *obj,int index,int value)
{
    if(index>=0 && index<=obj->length) {
        for (int i = obj->length - 1; i >=index; i--) {
            obj->A[i+1] = obj->A[i];
        }
        obj->A[index] = value;
    }
    obj->length++;
}

int max(class Array *obj)
{
    int max=obj->A[0];
    for(int i=1;i<obj->length;i++)
    {
        if(max<obj->A[i])           // for minimum min>obj->A[i]
            max=obj->A[i];
    }
    return max;
}

int sum(class Array obj,int n)
{
    if(n<0)
        return 0;
    else
        return sum(obj,n-1)+obj.A[n];
}

float avg(class Array obj)
{
    return float(sum(obj,obj.length))/float(obj.length);
}

void reverse(class Array *obj)              // if i had written obj only then it means copy of array not the actual one
{
    int temp;
    for(int i=0;i<obj->length/2;i++)
    {
        temp=obj->A[i];
        obj->A[i]=obj->A[obj->length-(i+1)];
        obj->A[obj->length-(i+1)]=temp;
    }
}

void leftShift(class Array *obj)
{
    int i;
    for(i=0;i<obj->length-1;i++)
    {
        obj->A[i]=obj->A[i+1];
    }
    obj->A[i]=0;
}

void display(class Array obj)
{
    for(int i=0;i<obj.length;i++)
    {
        cout<<" "<<obj.A[i];
    }
    cout<<"\n";
}

void insert(class Array *obj,int value)             //inserting in sorted array
{
    int i=obj->length-1;
    while(value<obj->A[i])
    {
        obj->A[i+1]=obj->A[i];
        i--;
    }
    obj->A[i+1]=value;
    obj->length++;
}

bool isSorted(class Array obj)
{
    for(int i=0;i<obj.length-1;i++)
    {
        if(obj.A[i]>obj.A[i+1])
            return false;
    }
    return true;
}

void negativeOnLeft(class Array *obj)
{
    int i=0,j=obj->length-1,temp,count=0;
    while(i<j)
    {
        while(obj->A[i]<0) {
            count++;
            i++;
        }
        while(obj->A[j]>0) {
            count++;
            j--;
        }
        if(i<j)
        {
            temp=obj->A[i];
            obj->A[i]=obj->A[j];
            obj->A[j]=temp;
            ++i;
            --j;
        }
    }
    cout<<"\niteration = "<<count<<"\n";
}

void mergeArray(Array *obj1,Array *obj2,Array *objMerge)
{
    int i=0,j=0,k=0;
    while(i<obj1->length && j<obj2->length)
    {
        if(obj1->A[i]<obj2->A[j])
        {
            objMerge->A[k++]=obj1->A[i++];
        }
        else{
            objMerge->A[k++]=obj2->A[j++];          // first swap then increment
        }
    }
    for(;i<obj1->length;i++)            // one or multiple values from i or j will be remaining always, that has to be copied
        objMerge->A[k++]=obj1->A[i];          // i and j need not to be declared as they already have values
    for(;i<obj2->length;j++)
        objMerge->A[k++]=obj2->A[j];
}
int main() {
    class Array obj{{1,4,5,6,2}},obj2{},obj3{},obj4{},obj5{},objMerge{};
                                                            // {} empty braces means don't initialise it right now
    obj.length=5;
    cout<<get(&obj,4)<<"\n";

    set(&obj,2,50);
    cout<<obj.A[2]<<"\n";

    cout<<max(&obj)<<"\n";

    cout<<avg(obj)<<"\n";

    reverse(&obj);
    display(obj);

    leftShift(&obj);
    display(obj);

    obj2={1,3,5,7,9};           // why this worked bcz the variable obj is pointing to 1 member of class
    obj2.length=5;                                      // i placed it above initialization of array and length got 0,
                                                        // bcz after that obj2 is again initialised and then length becomes 0;
    insert(&obj2,4);
    display(obj2);

    cout<<"obj isSorted = "<<isSorted(obj);
    cout<<"\nobj2 isSorted = "<<isSorted(obj2);

    obj3={-6,3,-8,10,5,-7,-9,12,-4,2,10};    // another way of initialising object
    negativeOnLeft(&obj3);
    display(obj3);

    obj4={{3,8,16,20,25},5};
    obj5={{4,10,12,22,23},5};

    objMerge.length=obj4.length+obj5.length;
    mergeArray(&obj4,&obj5,&objMerge);
    display(objMerge);
    return 0;
}
