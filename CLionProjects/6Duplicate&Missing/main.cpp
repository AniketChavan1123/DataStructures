#include <iostream>
using namespace std;
class Array
{
    private:
    int *A;
    int length;
public:
    Array()
    {
        this->length=10;
        A=new int[length];
    }
    ~Array()
    {
        delete []A;
    }

    explicit Array(int length)
    {
        this->length=length;
        A=new int[length];
    }
    static Array* dataEntry(int length)
    {
        auto *obj=new Array(length);
        for(int i=0;i<length;i++)
        {
            cin>>obj->A[i];
        }
        return obj;
    }
    void single()                   //for sorted Array
    {
        int low=A[0];
        int high=A[length-1];
        int sum=0;
        for(int i=0;i<length;i++)
        {
            sum=sum+A[i];
        }
        cout<<"Element missing is "<<(((high+low)*(high-low+1))/2)-sum;

        //Alternative method

        for(int i=0;i<length;i++)
        {
            if(A[i]-i!=A[0])        //A[i]-Currentindex     must be constant
            {
                cout<<"Element missing is "<<i+A[0];
                break;
            }
        }
    }
    void multiple()                         // for sorted Array
    {
        int diff=A[0];
        for(int i=0;i<length;i++)
        {
            if(A[i]-i!=diff)
            {
                while(diff<A[i]-i) {
                    cout << "\nMissing elements is" << diff + i;
                    diff++;
                }
            }
        }
    }
    void Uhashing(){
        int low=A[0],high=A[0];
        for(int i=1;i<length;i++)
        {
            if(low>A[i])
            {
                low=A[i];
            }
            else if(high<A[i])
            {
                high=A[i];
            }
        }
        high++;
        int hash[high];
        for(int i=0;i<high;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<length;i++)
        {
            hash[A[i]]++;
        }
        for(int i=low;i<high;i++)
        {
            if(hash[i]==0)
                cout<<"\nElement "<<i<<" is missing\n";
        }
    }
    void AUhashing(){                   //Uhashing with less space complexity
        int low=A[0],high=A[0];
        for(int i=1;i<length;i++)
        {
            if(low>A[i])
            {
                low=A[i];
            }
            else if(high<A[i])
            {
                high=A[i];
            }
        }
        int size=high-low;
        size++;
        int hash[size];
        for(int i=0;i<size;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<length;i++)
        {
            hash[A[i]-low]++;
        }
        for(int i=0;i<size;i++)
        {
            if(hash[i]==0)
                cout<<"\nElement "<<i+low<<" is missing\n";
        }
    }
    void DSorted(){                     //strictly for sorted arrays
        int lastDuplicate=0;
        for(int i=0;i<length-1;i++)
        {
            if(A[i]==A[i+1] && lastDuplicate!=A[i])
            {
                cout<<A[i]<<" is duplicated\n";
                lastDuplicate=A[i];
            }
        }

        // Alternative method
        for(int i=0;i<length-1;i++) {
            if (A[i] == A[i + 1]) {
                int k = i + 2;
                for (; A[k] == A[i]; ++k) {}
                cout << A[i] << " is duplicated " << k - (i + 1) << " times\n";
                i = k;
            }
        }
    }
    void DHsorted()
    {
        int size=A[length-1]-A[0];
        size++;
        int hash[size];
        for(int i=0;i<size;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<length;i++)
        {
            hash[A[i]-A[0]]++;
        }
        for(int i=0;i<size;i++)
        {
            if(hash[i]>1)
            {
                cout<<i+A[0]<<" is repeted "<<hash[i]-1<<"\n";
            }
        }
    }

    void DHUnsorted()
    {
        int low=A[0],high=A[0];
        for(int i=1;i<length;i++)
        {
            if(low>A[i])
            {
                low=A[i];
            }
            else if(high<A[i])
            {
                high=A[i];
            }
        }
        int size=high-low;
        size++;
        int hash[size];
        for(int i=0;i<size;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<length;i++)
        {
            hash[A[i]-low]++;
        }
        for(int i=0;i<size;i++)
        {
            if(hash[i]>1)
            {
                cout<<i+low<<" is repeted "<<hash[i]-1<<"\n";
            }
        }
    }
    void DUnsorted()
    {
        int count;
        for(int i=0;i<length-1;i++)
        {
            count=0;
            if(A[i]!=-1) {
                for (int j = i + 1; j < length; j++) {
                    if (A[i] == A[j]) {
                        count++;
                        A[j] = -1;            // so we don't repeat it again
                    }
                }
               if(count>0) cout<<A[i]<<" is repeated "<<count<<" times\n";
            }
        }
    }
    void SumSorted(int k)
    {
        if(k<A[length-1]+A[length-2])
        {
            int i=0,j=length-1,neededElement;
            while(i<j)
            {
                neededElement=k-A[i];
                if(neededElement==A[j])
                {
                    cout<<A[i]<<" + "<<A[j]<<" = "<<k<<"\n";
                    j--;i++;
                }
                else if(A[j]<neededElement)
                {
                    i++;
                }
                else j--;
            }

            //Alternative
            i=0;
            j=length-1;
            while(i<j)
            {
                neededElement=k-A[i];
                while(A[j]>neededElement){
                    j--;
                }
                if(A[j]==neededElement)
                {
                    cout<<A[i]<<" + "<<A[j]<<" = "<<k<<"\n";
                    j--;i++;
                }
                else if(A[j]<neededElement)
                {
                    i++;
                }
            }
        }
    }
    void sumUnsorted(int k)
    {
        int neededElement;
        for(int i=0;i<length-1;i++)
        {
            neededElement=k-A[i];
            for(int j=i+1;j<length;j++)
            {
                if(A[j]==neededElement) {
                    cout << A[i] << " + " << A[j] << " = " << k<<"\n";
                    break;
                }
            }
        }
    }
    void sumUnsortedHashing(int k)
    {
        int low=A[0],high=A[0];
        for(int i=1;i<length;i++)
        {
            if(low>A[i])
            {
                low=A[i];
            }
            else if(high<A[i])
            {
                high=A[i];
            }
        }
        int size=high-low;
        size++;
        int hash[size];
        for(int i=0;i<size;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<length;i++)
        {
            hash[A[i]-low]++;
        }
        for(int i=0;i<length;i++)
        {
            int neededElement=k-A[i];
            if(hash[neededElement-low]>0 &&(neededElement-low)>-1) {
                if(neededElement*2==k) {
                    if(hash[neededElement-low]>1)
                    cout << A[i] << " + " << neededElement << " = " << k << "\n";
                }
                else if(neededElement*2!=k)
                    cout << A[i] << " + " << neededElement << " = " << k << "\n";
            }
        }
    }

};


int main() {
    class Array *arr1;
    cout<<"1.single missing for sorted\n";
    cout<<"2.multiple missing for sorted\n";
    cout<<"3.Find Missing Using Hashing For UnSorted And Sorted\n";
    cout<<"4.Find duplicate elements in sorted Array\n";
    cout<<"5.Find duplicate elements in sorted Array using Hashing\n";
    cout<<"6.Find duplicate elements in Unsorted Array using hashing\n";
    cout<<"7.Find duplicate elements in Unsorted Array without hashing\n";
    cout<<"8.Sum of sorted element\n";
    cout<<"9.Sum of Unsorted element\n";
    cout<<"10.Sum of Unsorted element using Hashing\n";

    int n,ch;
    cout<<"Enter no of elements";
    cin>>n;
    arr1=Array::dataEntry(n);
    cout<<"Enter the operation choice";
    cin>>ch;
    switch(ch)
    {
        case 1:arr1->single();    // finding single missing element
            break;
        case 2:arr1->multiple();
        break;
        case 3://arr1->Uhashing();
        arr1->AUhashing();
        break;
        case 4:arr1->DSorted();
        break;
        case 5:arr1->DHsorted();
        break;
        case 6:arr1->DHUnsorted();
            break;
        case 7:arr1->DUnsorted();
            break;
        case 8:arr1->SumSorted(10);
        break;
        case 9:arr1->sumUnsorted(10);
            break;
        case 10:arr1->sumUnsortedHashing(10);
            break;
        default:cout<<"invalid input";
    }

    return 0;
}
