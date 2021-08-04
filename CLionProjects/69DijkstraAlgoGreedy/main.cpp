#include <iostream>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int diag[7][7]={{0,0,0,0,0,0,0},
                    {0,0,50,45,10,99,99},
                    {0,99,10,15,99,99,99},
                    {0,99,99,0,99,30,99},
                    {0,10,99,99,0,15,99},
                    {0,99,20,35,99,0,99},
                    {0,99,99,99,99,99,0}};
    int visited[7]={0,1,0,0,0,0,0};
    cout<<endl;
    int counter=1,start;
    start=1;
    while(counter<6){
        int min=99,vertexNo;
        for(int k=1;k<7;k++) {
            if (min >= diag[start][k] && diag[start][k] != 0 && visited[k]==0) {
                min = diag[start][k];
                vertexNo = k;
            }
        }
        if(visited[vertexNo]==0) {
            visited[vertexNo] = 1;
            cout<<vertexNo<<"\t";
            ++counter;
        }

        for(int j=1;j<7;j++)
        {
            if(diag[start][j]!=0 && visited[j]==0)
            {
                if(diag[start][vertexNo]+diag[vertexNo][j]<=diag[start][j])
                {
                    diag[start][j]=diag[start][vertexNo]+diag[vertexNo][j];

                }
            }
        }
        start=vertexNo;
    }
    cout<<"\n\n\n";
    for(int i=1;i<7;i++)
    {
        cout<<visited[i]<<"\t";
    }
    cout<<"\n\n\n";
    for(int i=1;i<7;i++)
    {
        for(int j=1;j<7;j++)
            cout<<"\t"<<diag[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
