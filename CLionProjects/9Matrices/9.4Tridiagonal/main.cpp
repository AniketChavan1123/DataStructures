#include <iostream>
using namespace std;

class TriDiagonal{
private:
    int n;
    int *A;
public:
    TriDiagonal(): n(2) ,A(new int[2]){}       //default constructor
    explicit TriDiagonal(int n){
        this->n=n;
        A=new int[3*n-2];
    }
    void setInto(int i,int j,int x);
    static int absFunc(int res);            // common function for every object
    void display()const;
    static int findIndex(int i,int j,int n);
    void getNum(int i,int j);
    ~TriDiagonal(){
        delete []A;
    }
};
void TriDiagonal::setInto(int i, int j, int x) {
    int res=absFunc(i-j);
    int index;
    if(res<=1) {
        index=findIndex(i,j,n);
        A[index] = x;
    }
}
void TriDiagonal::getNum(int i,int j)
{
    int res=absFunc(i-j);
    int index;
    if(res<=1) {
        index=findIndex(i,j,n);
        cout<<A[index];
    }
}
int TriDiagonal::findIndex(int i,int j,int n)
{
    int index;
    if (i - j == 1) {
        index = i - 1;
    } else if (i - j == 0) {
        index = (n-1) + i;
    } else {
        index = n + (n - 1) + i;
    }
    return index;
}
void TriDiagonal::display()const{
    int res,index;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j <n ; ++j) {
            res=absFunc(i-j);
            if(res<=1) {
                index=findIndex(i,j,n);
                cout << A[index] << " ";
            }
            else{
                cout<<"0"<<" ";
            }
        }cout<<endl;
    }
}
int TriDiagonal::absFunc(int res) {        // bcz we don't want it to be created to every object
    if(res<0)                           // static used when:can only access static data member
        return res*(-1);                // as static member are not bound to object so they can be
                                        // invoked using class name ,no need of object.funcName
    return res;
}

int main() {

    int no,n;
    cout<<"Enter a no: ";
    cin>>no;
    TriDiagonal obj(no);
    for(int i=0;i<no;i++)
    {
        for(int j=0;j<no;j++)
        {
            cin>>n;
            obj.setInto(i,j,n);
        }
    }
    obj.display();
    return 0;
}
