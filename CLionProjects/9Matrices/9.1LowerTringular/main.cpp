#include <iostream>
using namespace std;

class LowerTri{
private:
    int n;
    int *A;
public:
    LowerTri()
    {
        n=2;
        A=new int[2];
    }
    explicit LowerTri(int n)
    {
        this->n=n;
        A=new int[(n*(n+1))/2];
    }
    void display(bool check);
    void setColumn(int i,int j,int x);
    int getColumn(int i,int j);
    int getRow(int i,int j);
    int dimension()const;
    static int rowIndex(int i,int j);// because it is not accessing any data member
    int columnIndex(int i,int j)const;
    void setRow(int i,int j,int x);
    void disp();
    ~LowerTri(){
        delete []A;       //The delete operator deallocatesmemory & calls the destructor for a single
                        // object created with 'new'.
                        //The delete[] operator deallocates memory and calls destructor for an array of
                        //object created with new[]
                        //here array of object means new int[], whenever new is used a object is created
    }
};
int LowerTri::rowIndex(int i,int j) {
    return (((i*(i+1))/2)+j);
}
/*
  Just like the static data members or static variables inside the class, static member functions
  also does not depend on object of class. We are allowed to invoke a static member function using
  the object and the ‘.’ operator but it is recommended to invoke the static members using the class
  name and the scope resolution operator.
Static member functions are allowed to access only the static data members or other static member functions,
 they can not access the non-static data members or member functions of the class*/
int LowerTri::columnIndex(int i,int j)const {
    return (((n*(n+1)/2)-((n-j)*((n-j)+1)/2))+(i-j));
}
void LowerTri::setRow(int i, int j, int x) {
    if(i>=j)
    {
        int index=rowIndex(i,j);
        A[index]=x;
    }
}
void LowerTri::setColumn(int i,int j,int x){
    if(i>=j)
    {
        int index=columnIndex(i,j);
        A[index]=x;
    }
}
int LowerTri::getColumn(int i, int j) {
    if(i>=j)
    {
        int index=columnIndex(i,j);
        return A[index];
    }
    return 0;
}
int LowerTri::getRow(int i, int j) {
    if(i>=j)
    {
        int index=rowIndex(i,j);
        return A[index];
    }
    return 0;
}
int LowerTri::dimension()const {return n;}
/*When a function is declared as const, it can be called on any type of object, const object
 * as well as non-const objects.
 Whenever an object is declared as const, it needs to be initialized at the time of declaration.
 however, the object initialization while declaring is possible only with the help of constructors.*/

void LowerTri::display(bool check)
{
    if(check)
    {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i>=j)
                    cout<<A[rowIndex(i,j)]<<" ";
                else
                    cout<<"0 ";
            }
            cout<<"\n";
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i>=j)
                    cout<<A[columnIndex(i,j)]<<" ";
                else
                    cout<<"0 ";
            }cout<<"\n";
        }
    }
}
void LowerTri::disp()
{
    for(int i=0;i<n*(n+1)/2;++i)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    int n;
    cout<<"Enter 25 no";
    LowerTri objRow(4);
    for(int i=0;i<4;i++) {
        for (int j = 0; j < 4;j++) {
            cin>>n;
            objRow.setColumn(i, j, n);  //for row set Row
        }
    }
    objRow.disp();
    objRow.display(false);      // for Row it's true
    cout<<objRow.dimension();//non const object can call const function
    //const functions ensure not to modify the object.
    return 0;
}
