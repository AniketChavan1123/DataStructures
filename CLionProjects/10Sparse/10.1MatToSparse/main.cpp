#include <iostream>
using namespace std;
class Element{
public:
    int i,j,k;
};
class Sparse{
public:
    int n;
    Element *E;
    explicit Sparse(int count){
        n=count;
        E=new Element[count];
    }
    void display()const{
        for(int i=0;i<n;i++)
        {
            cout<<E[i].i<<" "<<E[i].j<<" "<<E[i].k;
            cout<<"\n";
        }
    }
    ~Sparse(){
        delete []E;
    }
};

int main() {
    int count=0,m,n;
    cout<<"Enter Dimensions";
    cin>>m>>n;
    int A[m][n];
    for(int i=0;i<m;i++)
    {
        for (int j = 0; j <n; ++j) {
            cin>>A[i][j];
            if(A[i][j]!=0)
                count++;
        }
    }
    Sparse obj(count);
    count=0;
    for (int i = 0; i <m; ++i) {
        for (int j = 0; j < n; ++j) {
                if(A[i][j]!=0)
                {
                    obj.E[count].i=i;
                    obj.E[count].j=j;
                    obj.E[count].k=A[i][j];
                    count++;
                }
        }
    }
    obj.display();

}
