#include <iostream>
using namespace std;
class UpperTri{
private:
    int n;
    int *A;
public:
    UpperTri(): n(2),A(new int[4]){}
    explicit UpperTri(int n): n(n),A(new int[n*(n-1)/2]){}
    void setIntoRow(int i,int j,int x);
    void setIntoCol(int i,int j,int x);
    void displayRow();
    void displayCol();
    void disp();
    ~UpperTri(){
        delete []A;
    }
};
void UpperTri::setIntoRow(int i, int j, int x) {
    int index;
    if(i<=j)
    {
        index=((n*(n+1)-((n-i)*((n-i)+1)))/2+(j-i));
        A[index]=x;
    }
}
void UpperTri::setIntoCol(int i, int j, int x) {
    int index;
    if(i<=j)
    {
        index=((j*(j+1))/2)+i;
        A[index]=x;
    }
}
void UpperTri::displayRow()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i<=j)
            {
                int index;
                index=((n*(n+1)-((n-i)*((n-i)+1)))/2+(j-i));
                cout<<A[index]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }cout<<endl;
    }
}
void UpperTri::displayCol()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i<=j)
            {
                int index;
                index=((j*(j+1))/2)+i;
                cout<<A[index]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }cout<<endl;
    }
}
void UpperTri::disp()
{
    for(int i=0;i<n*(n+1)/2;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main() {
    int no,n;
    cout<<"Enter the No: ";
    cin>>no;
    UpperTri obj(no);
    for(int i=0;i<no;i++)
    {
        for (int j = 0; j < no; ++j) {
            cin>>n;
//            obj.setIntoRow(i,j,n);
            obj.setIntoCol(i,j,n);              // use setIntoRow interchangeably
        }
    }
//    obj.displayRow();
obj.disp();
    cout<<"\n";
    obj.displayCol();
    return 0;
}
