#include<iostream>
using namespace std;
class node{
 private:
    int data;
    node *next;
    node *prev;
     public:
        void insertData();
        void printData();
};
node *head=0;
void node::insertData()
{
    int d;
    head=new node();
    cout<<"Enter data : ";
    cin>>d;
    head->prev=0;
    head->data=d;
    head->next=0;
    node *top;
    top=head;
    node *newnode;
    int c=0;
    cout<<"Do you want to continue if yes press 1 else press : ";
    cin>>c;
    while (c==1)
    {
        newnode=new node();
        cout<<"Enter data : ";
        cin>>newnode->data;
        newnode->next=0;
        newnode->prev=0;
        top->next=newnode;
        top=top->next;
        cout<<"Do you want to continue if yes press 1 and press 2 : ";
        cin>>c;
    }
}

void node::printData()
{
    node *top;
    top=head;
    while(top!=0)
    {
    cout<<top->data<<" ";
    top=top->next;
    }
}

int main()
{
    node obj;
    obj.insertData();
    obj.printData();
}