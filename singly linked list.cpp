#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
     void setData();
    void printData();
};

node* head =0;
void node::setData()
{
	int choice=1;
	head=new node();
    cout <<"Enter data : ";
    cin>>head->data;
    head->next=NULL;
    node* temp;
    temp=head;
    node* newnode;
     cout<<"Do you want to link another list if yes press 1 else press 2 : ";
    cin>>choice;
    while(choice==1)
    {
    newnode=new node();
    cout <<"\nEnter data : ";
	cin>>newnode->data;
    newnode->next=0;
    temp->next=newnode;
    temp=temp->next;
    cout<<"\nDo you want to link another list if yes press 1 else press 2 : ";
    cin>>choice;
    }
}

void node::printData ()
{
	cout<<"\n\nPrinting Linked List........\n\n";
    node* temp;
    temp=head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){

    node obj;
    obj.setData();
    obj.printData();
}