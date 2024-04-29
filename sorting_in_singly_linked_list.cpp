#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		void insertData();
		void printData();
		void sorting();
};
node* head=0;
void node::insertData(){
	int c=1;
	head=new node();
	cout<<"Enter data : ";
	cin>>head->data;
	head->next=NULL;
	node *temp;
	temp=head;
	node *newnode;
	cout<<"Do you want to link another list if yes press 1 else press 2 : ";
	cin>>c;
	while(c==1)
	{
		newnode=new node();
		cout<<"Enter data : ";
		cin>>newnode->data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
		cout<<"Do you want to link another list if yes press 1 else press 2 : ";
		cin>>c;
	 } 
}

void node::sorting()
{
	node* temp;
	temp=head;
	node* newnode;
	int tmp;
	
	while(temp!=NULL)
	{
		newnode=temp->next;
		while(newnode!=NULL)
		{
		if(temp->data>newnode->data)
		{
			tmp=temp->data;
			temp->data=newnode->data;
			newnode->data=tmp;
		}
		newnode=newnode->next;
	}
	temp=temp->next;
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
	node *obj;
	obj->insertData();
	cout<<"\n\nBefore Sorting ......\n\n";
	obj->printData();
	obj->sorting();
	cout<<"\n\nAfter sorting........\n\n";
	obj->printData();
	return 0;
}