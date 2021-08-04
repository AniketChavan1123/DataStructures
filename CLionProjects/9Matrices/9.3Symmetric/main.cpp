#include <iostream>
using namespace std;

class Symmetric{
private:
    int n;
    int *A;
public:
    Symmetric() : n(2), A(new int[4]) {}
    explicit Symmetric(int n) : n(n), A(new int[n*(n+1)/2]) {}//explicit ,prevent automatic type conversion
    void setInto(int i,int j,int x);
    void display()const;
    void disp()const;
    ~Symmetric(){
        delete []A;
    }
};
void Symmetric::setInto(int i, int j, int x) {
    int index;
    if(i>=j)
    {
        index=(i*(i+1)/2)+j;
        A[index]=x;
    }
}
void Symmetric::display()const
{
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; ++j) {
            int index;
            if(j>i)
            {
                index=(j*(j+1)/2)+i;
                cout<<A[index]<<" ";
            }
            else {
                index = (i * (i + 1) / 2) + j;
                cout << A[index] << " ";
            }
        }cout<<endl;
    }
}
void Symmetric::disp()const{
    for(int i=0;i<n*(n+1)/2;i++)
    cout<<A[i];
}
int main() {
    int no,n;
    cout<<"enter a number: ";
    cin>>no;
    Symmetric obj(no);
    for (int i = 0; i < no; ++i) {
        for (int j = 0; j < no; ++j) {
            cin>>n;
            obj.setInto(i,j,n);
        }
    }
    obj.display();
    cout<<"\n";
    obj.disp();
    return 0;
}
