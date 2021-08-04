#include <iostream>
#include <cmath>

using namespace  std;

class Term{
public:
    int coef;
    int expo;
};
class Polynomial{
public:
    int num;                // total no. of terms
    Term *poly;
    explicit Polynomial(int num){
        this->num=num;
        poly=new Term[num];
    }
    friend istream &operator>>(istream &is,Polynomial &p);
    friend ostream &operator<<(ostream &os,Polynomial &p);
    Polynomial operator+(Polynomial &p)const;
    void evaluate(int n)const;
    ~Polynomial()
    {
        delete []poly;
    }
};
istream &operator>>(istream &is,Polynomial &p){
    for(int i=0;i<p.num;i++)
    {
        cin>>p.poly[i].coef>>p.poly[i].expo;
    }
    return is;
}
ostream &operator<<(ostream &os,Polynomial &p)
{
    for(int i=0;i<p.num;i++)
    {
        cout<<p.poly[i].coef<<"(X)"<<p.poly[i].expo;
        if(i!=p.num-1)
        {
            cout<<" + ";
        }
    }
    return os;
}
void Polynomial::evaluate(int n) const {
    double sum=0;
    for(int i=0;i<num;i++)
    {
        sum=sum+(poly[i].coef*(pow(n,poly[i].expo)));
    }
    cout<<"Value :"<<sum;
}
Polynomial Polynomial::operator+(Polynomial &p)const   //as we are not doing modification of obj and obj2
{
    Polynomial newp(num+p.num);
    int i,j,k;
    i=j=k=0;
    while(i<num && j<p.num)
    {
        if(poly[i].expo>p.poly[j].expo)
        {
            newp.poly[k++]=poly[i++];
        }
        else if(poly[i].expo<p.poly[j].expo){
            newp.poly[k++]=p.poly[j++];
        }
        else{
                newp.poly[k]=p.poly[j];
                newp.poly[k++].coef=p.poly[j++].coef+poly[i++].coef;
        }
    }
    for(;i<num;i++)
    {
        newp.poly[k++]=p.poly[i];
    }
    for(;j<num;j++)
    {
        newp.poly[k++]=p.poly[j];
    }
    newp.num=k;
    return newp;
}

int main() {
    int n,n1;
    cout<<"Enter no of non zero element";
    cin>>n;
    cout<<"\nEnter no of non zero element";
    cin>>n1;
    class Polynomial obj(n),obj2(n1);
    cin>>obj;
    cout<<obj;
    cin>>obj2;
    cout<<obj2;
    Polynomial obj3=obj+obj2;
    cout<<"\n\n\n\n";
    cout<<obj3;
    obj.evaluate(5);
    return 0;
}
