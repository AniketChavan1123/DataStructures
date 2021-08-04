#include<iostream>
using namespace std;
class Array{
public :
    int *A;
int size;
int length;

void display() const
{
    for(int i=0;i<length;i++)
    {
        std::cout<<"\n"<<A[i];
    }
}

};
void append(class Array *obj,int n)     //making obj as pointer to object of class type Array
{
    if(obj->length<obj->size) {         // checking availability of space
        obj->A[obj->length] = n;              // O(1)
        obj->length += 1;
    }
}
void insert(class Array *obj,int index,int x)
{
    if(index>=0 && index<=obj->length) {
        for (int i = obj->length; i > index; i--) {
            obj->A[i] = obj->A[i - 1];                  // best case - O(1)        worst case - O(n)
        }                                           // when insert at last     when inserted at first
        obj->A[index] = x;                            // same analysis for delete operation
        obj->length++;                // increment after insert
    }

}
void deleteFrom(class Array *obj,int index)
{
    if(index>=0 && index<=obj->length-1) {
        for (int i = index; i < obj->length - 1; i++) {
            obj->A[i] = obj->A[i + 1];
        }
        obj->length--;
    }
}
void swap(int *x,int *y)                         // why use pointer -> to make changes in original array
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(class Array obj,int key)          // class object passed by value bot by address
{
    for(int i=0;i<obj.length;i++)
    {
        if(key==obj.A[i])
        {
            swap(obj.A[i],obj.A[0]);            // alternate method---->swap(A[i],A[i-1]);
            return 0;
        }
    }
    return -1;
}
int BinarySearch(class Array *obj,int low,int high,int key)
{
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==obj->A[mid])
        {
            return mid;
        }
        else if(key<obj->A[mid])
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return -1;
}
int recurseSearch(class Array *obj, int low, int high, int key)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(key==obj->A[mid])
        {
            return mid;
        }
        else if(key<obj->A[mid])
        {
            return recurseSearch(obj,low,mid-1,key);          // passing obj value as it contains the address of original object
        }
        else
        {
            return recurseSearch(obj,mid+1,high,key);
        }
    }
    return -1;                      // if not found
}
int main()
{
    class Array object{};       // if you don't put brackets it means uninitialised object
                                // or you can initialised object like object{{1,2,3},10,3};
    int n;                      // initialise array like above method to observe debugging process.
    std::cout<<"\nEnter size";
    std::cin>>object.size;
    object.A=new int[object.size];
    object.length=0;
    std::cout<<"\nEnter a number";
    std::cin>>n;
    std::cout<<"\nEnter inputs";
    for(int i=0;i<n;i++)
    {
        std::cin>>object.A[i];
    }
    object.length=n;               // mentioning Array length after entering array Elements
    append(&object,72);         // passing address of object as argument to a non member function obviously
    insert(&object,4,550);
    deleteFrom(&object,4);
    object.display();
    std::cout<<"\n"<<LinearSearch(object,72);           //calling by value
    int key;                            // mute LinearSearch on performing below operation
    std::cout<<"Enter a number to find";
    std::cin>>key;
    std::cout << "Element found at" << BinarySearch(&object,0,object.length-1,key)
     << recurseSearch(&object, 0,object.length - 1,key);

}