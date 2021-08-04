#include <iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
public:
    Array()                 // as object is created in main constructor is called
    {
        size=10;
        A=new int[size];
    }
    explicit Array(int size)          // parameterized constructor
    {                               //search for What does explicit conversion mean on StackOverflow
        this->size=size;
        A=new int[size];
    }
    ~Array(){               // we are creating array dynamically that has to be deleted
        delete []A;          // delete array name A
    }
    //By declaring a function member as static, you make it independent of any particular
    // object of the class. A static member function can be called even if no objects of the
    // class exist and the static functions are accessed using only the class name and the
    // scope resolution operator
static Array* Merge(Array *obj1,Array *obj2)               // for more refer to pointer to integer topic
{
        int i=0,j=0,k=0;
    auto *obj3=new Array(obj1->size+obj2->size);
    //Clang-Tidy: Use auto when initializing with new to avoid duplicating the type name
    while(i<obj1->size && j<obj2->size)
    {
        if(obj1->A[i]<obj2->A[j])
        {
            obj3->A[k++]=obj1->A[i++];
        }
        else if(obj1->A[i]==obj2->A[j]){j++;i++;}
        else{obj3->A[k++]=obj2->A[j++];}
    }
    for(;i<obj1->size;)
        obj3->A[k++]=obj1->A[i++];
    for(;i<obj1->size;)
        obj3->A[k++]=obj2->A[j++];
    return obj3;
}
void enter();
    void display();
};
void Array::enter()
{
    for(int i=0;i<size;i++)           // why no object.length bcz it recognizes current object
        {                               // as function is declared in class
        cin>>A[i];
    }
}
void Array::display()
{
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main() {
    class Array obj1(7),obj2(5),*obj3;
    obj1.enter();
    obj2.enter();
    obj3=Array::Merge(&obj1,&obj2);
    obj3->display();
   return 0;
}
