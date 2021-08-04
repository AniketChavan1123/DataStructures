#include <iostream>
using namespace std;

class Element{
public:
    int i;
    int j;
    int x;
};
class Sparse{
private:
    int m;
    int n;
    int num;
    Element *E;
public:
    Sparse(int m, int n, int num);
    ~Sparse(){
        delete []E;
    }
    void read()const;
    void display()const;
    friend Sparse* add(Sparse,Sparse);
};
Sparse::Sparse(int m, int n, int num) : m(m), n(n), num(num) {
    E=new Element[num];
}
void Sparse::read()const {
    int a;
    for(a=0;a<num;a++)
    {
        cin>>E[a].i>>E[a].j>>E[a].x;
    }
}
void Sparse::display()const {
    int k=0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if((E[k].i)-1==i && (E[k].j)-1==j)
            {
                cout<<E[k++].x<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}
Sparse* add(Sparse const s1,Sparse const s2)
{// parameters const indicates that the function promises not to change these values
    int k,i,j;
    j=i=k=0;
    Sparse *s3;         // if we would have created obj then we would need to initialise it first;
    if(s1.m!=s2.m && s1.n==s2.n)
        return nullptr;
    s3=new Sparse(s1.m,s2.n,s1.num+s2.num);

    while(i<s1.num && j<s2.num)
    {
        if(s1.E[i].i<s2.E[j].i)
            s3->E[k++]=s1.E[i++];
        else if(s1.E[i].i > s2.E[j].i)
            s3->E[k++]=s2.E[j++];
        else{
            if(s1.E[i].j<s2.E[j].j)
                s3->E[k++]=s1.E[i++];
            else if(s1.E[i].j>s2.E[j].j)
                s3->E[k++]=s2.E[j++];
            else {
                s3->E[k]=s1.E[i];
                s3->E[k++].x=s1.E[i++].x+s2.E[j++].x;
            }
        }
    }
    for(;i<s1.num;i++)
    {
        s3->E[k++]=s1.E[i];
    }
    for(;j<s2.num;j++)
    {
        s3->E[k++]=s1.E[j];
    }
    s3->num=k;
    return  s3;
}



int main() {
    Sparse s(5,6,5),s1(5,6,6),*s3;
    s.read();
    s.display();
    s1.read();
    s1.display();
    s3=add(s,s1);
    s3->display();
    return 0;
}
