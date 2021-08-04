#include <iostream>
using namespace std;
class DisjointSet{
public:
    int *arr,nodes,edges;
    int edgesTable[][3];

    void Union(int,int) const;
    int findParent(int) const;
    void showArray() const;

    explicit DisjointSet(int n,int edges)
    {
        nodes=n;
        this->edges=edges;
        arr=new int[nodes];
        for(int i=0;i<nodes;i++)
        {
            arr[i]=-1;          // assigning all values to -1;
        }

    }
};
void DisjointSet::showArray() const {
    for(int i=0;i<nodes;i++)
    {
        cout<<arr[i]<<"\t";
    }
}

void DisjointSet::Union(int m,int n) const {

    int p,q;
    p= findParent(m);
    q= findParent(n);
    if(arr[p]<=arr[q])              // checking values of parent and parent must not be same
    {
        if(p!=q) {
            arr[p] += arr[q];             //updating parent value
            arr[q] = p;
        }//changing parent
    }
    else{
        arr[q]+=arr[p];
        arr[p]=q;
    }
}
int DisjointSet::findParent(int var) const
{
    if(arr[var]<0)  //if it is itself a parent
        return var;
    else {
        do {
            var = arr[var];
        } while (arr[var] > 0);      // while parent is not reached
    }

    return var;
}

int main() {
    int n,edges;
    cout<<"enter total vertex:";
    cin>>n;
    cout<<"\nenter total Edges:";
    cin>>edges;
    cin.ignore();
    DisjointSet obj(n+1,edges);
    for(int i=0;i<obj.edges;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>obj.edgesTable[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<obj.edges;i++) {
        obj.Union(obj.edgesTable[i][0], obj.edgesTable[i][1]);
    }
    obj.showArray();

    return 0;
}
