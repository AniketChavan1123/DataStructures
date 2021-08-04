#include <iostream>
using namespace std;

class knapsack
{
private:
    double capacity;
public:
    explicit knapsack(int capacity){
        this->capacity=capacity;
    }
    double pw[][3];
    void fillSack(int);
    int partition(int,int);
    void quickSort(int low, int high);
    void showTable(int);
    void findMaxProfit();
};
void knapsack::findMaxProfit() {
    double sum=0.0;
    int i;
    double profit=0;
    for(i=7;pw[i][1]<=capacity-sum;i--)
    {
            sum+=pw[i][1];
            profit+=pw[i][0];
    }
    if(sum<capacity)
    {
        profit+=pw[i][2]*(capacity-sum);
    }
    cout<<"\nYour profit"<<profit;

}
void knapsack::fillSack(int totalObj) {

    cout << "Enter profit and weight";
    for (int i = 0; i < totalObj; i++) {
        cin >> pw[i][0];
        cin >> pw[i][1];
        pw[i][2] = pw[i][0] / pw[i][1];
        cout << endl;
    }
    quickSort(0,totalObj-1);
}
void knapsack::showTable(int totalObj)
{
    for(int i=0;i<totalObj;i++)
    {
        cout<<pw[i][0]<<"\t"<<pw[i][1]<<"\t"<<pw[i][2];
        cout<<endl;
    }
}
void swap(double* x,double* y)
{
    double temp=*x;
    *x=*y;
    *y=temp;
}
int knapsack::partition(int low,int high)
{
    double pivot=pw[low][2];
    int i=low+1;
    int j=high;

    while(true){
        while(i<=j && pw[i][2]<=pivot){
            i++;
        }
        while(pw[j][2]>=pivot && j>=i){
            j--;
        }
        if(j<i){
            break;
        }else{
            swap(&pw[i][2],&pw[j][2]);
            swap(&pw[i][1],&pw[j][1]);
            swap(&pw[i][0],&pw[j][0]);

        }
    }
    swap(&pw[low][2],&pw[j][2]);
    swap(&pw[low][1],&pw[j][1]);
    swap(&pw[low][0],&pw[j][0]);

    return j;
}

void knapsack::quickSort(int low,int high)
{
    if(low < high){
        int p= partition(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }
}

int main() {
    knapsack obj(50);
    obj.fillSack(3);
    obj.showTable(3);
    obj.findMaxProfit();
    return 0;
}
