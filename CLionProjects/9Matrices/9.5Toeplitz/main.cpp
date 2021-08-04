#include <iostream>
using namespace std;
class Toeplitz{
private:
    int n;
    int *A;
public:
    Toeplitz(): n(2),A(new int[3]){}
    explicit Toeplitz(int n): n(n),A(new int[n+n-1]){}
    void setInput(int i,int j,int x);
    void display()const;
    void disp();
    ~Toeplitz(){
        delete []A;
    }
};
void Toeplitz::setInput(int i, int j, int x) {
    int index;
    if(i==0)
    {
        index=j-i;
        A[index]=x;
    }
    else if(j==0){
        index=n+(i-j);
        A[index]=x;
    }
}
void Toeplitz::display() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int index;
            if(i<=j)
            {
                index=j-i;
                cout<<A[index]<<" ";
            }
            else{
                index=n+(i-j);
                cout<<A[index]<<" ";
            }
        }
        cout<<endl;
    }
}
void Toeplitz::disp()
{
    for (int i = 0; i < n+n-1; ++i) {
        cout<<A[i];
    }
}
int main() {
    int no,n;
    cout<<"Enter a no: ";
    cin>>no;
    Toeplitz obj(no);
    for (int i = 0; i < no; ++i) {
        for (int j = 0; j < no; ++j) {
            cin>>n;
            obj.setInput(i,j,n);
        }
    }
    obj.display();
    return 0;
}
