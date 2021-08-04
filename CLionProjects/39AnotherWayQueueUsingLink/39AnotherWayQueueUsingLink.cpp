#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};

class link:private node{
    public:
    node *head,*tail;
    link(){
        head=tail=NULL;
    }
    void enqueue();
    void display();
    void dequeue();
      
};
    void link::enqueue(){
        node *temp=new node;
        cout<<"Enter data:";
        cin>>temp->data;
        temp->next=head;
        if(head==NULL){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }

    void link::display(){
        node *temp=new node;
        if(head==NULL){
            cout<<"Nothing to display";
            return;
        }
        temp=head;
        while(temp!=tail){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<temp->data;
    }

    void link::dequeue(){
        node *temp=new node;
        temp=head;
        head=head->next;
        tail->next=head;
         cout<<temp->data<<" is removed";
        free(temp);
    }

    int main()
    {
        link obj;
        int ch;
        for(;;)
        {
            cout<<"\nMENU";
            cout<<"\n1.Enqueue";
            cout<<"\n2.Dequeue";
            cout<<"\n3.Display";
            cout<<"\n4.Exit";
            cout<<"\n\nEnter your choice";
            cin>>ch;
            switch(ch){
                case 1:
                obj.enqueue();
                break;

                case 2:obj.dequeue();
                break;

                case 3:
                    obj.display();
                    break;
                case 4:
                exit(0);
            }
        }
        return 0;
    }