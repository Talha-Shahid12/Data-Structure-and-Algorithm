#include<iostream>
using namespace std;
class node{
	private:
		int data;
		node *next;
		public:
			void insertData(int);
			void printData(int);
};
node *head=0;
void node::insertData(int size)
{
	int d;
	cout<<"Enter data : ";
	cin>>d;
	head=new node();
	head->data=d;
	head->next=NULL;
	node *temp;
	temp=head;
	node *newnode;
	for(int i=1; i<size; i++)
	{
		newnode= new node();
		cin>>newnode->data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
		newnode->next=head;
	}
}

void node::printData(int size)
{
	node *temp;
	temp=head;
	for(int i=0; i<size; i++)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	node obj;
	int size;
	cout<<"Enter size for create a node : ";
	cin>>size;
	obj.insertData(size);
	obj.printData(size);
}