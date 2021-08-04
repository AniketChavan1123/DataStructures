#include <iostream>
using namespace std;
class Element{
public:
    int i,j,x;
};
class Sparse{
private:
    int m,n,num;
    Element *E;
public:
    Sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        E=new Element[this->num];
    }
    ~Sparse(){
        delete []E;
    }
    Sparse operator+(Sparse &s);                //for more visit cpp folder
    friend istream & operator>>(istream &is,Sparse &s);
    friend ostream & operator<<(ostream &os,Sparse &s);
};
Sparse Sparse::operator+(Sparse &s) {
    int i,j,k;

    if(m!=s.m || n!=s.n) {
        return Sparse(0, 0, 0);       //returning NULL Sparse
    }

        auto *sum=new Sparse(m,n,num+s.num);
        i=j=k=0;
        while(i<num && j<s.num)                     // num belongs to this object, and s.num is object received by function
        {
            if(E[i].i<s.E[j].i)
                sum->E[k++]=E[i++];
            else if(E[i].i>s.E[j].i)
                sum->E[k++]=s.E[j++];
            else{
                if(E[i].j<s.E[j].j)
                    sum->E[k++]=E[i++];
                else if(E[i].j>s.E[j].j)
                    sum->E[k++]=s.E[j++];
                else{
                    sum->E[k]=s.E[j];                // you can use E[i] also
                    sum->E[k++].x=E[i++].x+s.E[j++].x;
                }
            }
        }

        for(;i<num;i++)sum->E[k++]=E[i];
        for(;j<s.num;j++)sum->E[k++]=s.E[j];
        sum->num=k;

        return *sum;
}
istream &operator>>(istream &is,Sparse &s)
{
    cout<<"Enter non xero Elements";
    for(int i=0;i<s.num;i++)
    {
        cin>>s.E[i].i>>s.E[i].j>>s.E[i].x;
    }
    return is;
}
ostream &operator<<(ostream &os,Sparse &s)
{
    int k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if((s.E[k].i)-1==i && (s.E[k].j)-1==j)
                cout<<s.E[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    return os;
}


int main() {
    Sparse s1(5,5,5),s2(5,5,5);
    cin>>s1;
    cin>>s2;
    cout<<s1;
    cout<<s2;
    Sparse s3=s1+s2;                                     // if s3 declared separately  we would need to initialise it
    cout<<s3;
    return 0;
}
