#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
		void insertData();
		void printData();
		void deletion();
};
node* head=0;
void node::insertData()
{
	int c=1;
	head=new node();
	cout<<"Enter Data : ";
	cin>>head->data;
	head->next=0;
	head->prev=0;
	node* temp;
	temp=head;
	cout<<"Do you want to link another list if yes press 1 else press 2 : ";
	cin>>c;
	node *newnode;
	while(c==1)
	{
		newnode=new node();
		cout<<"Enter Data : ";
		cin>>newnode->data;
		newnode->next=0;
		newnode->prev=0;
		temp->next=newnode;
		temp=temp->next;
		cout<<"Do you want to link another list if yes press 1 else press 2 : ";
		cin>>c;
	}
}

void node::deletion()
{
	node* temp;
	temp=head;
	node *p;
	int num;
	cout<<"\nEnter number to which you are wanting to delete : ";
	cin>>num;
	while(temp!=0 && temp->data!=num)
	{
		p=temp;
		temp=temp->next;
	}
	if(temp!=0)
	{
		p->next=temp->next;
		delete(temp);
	}
}

void node::printData()
{
	node* temp;
	temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	node obj;
	obj.insertData();
	obj.printData();
	obj.deletion();
	obj.printData();
	
}