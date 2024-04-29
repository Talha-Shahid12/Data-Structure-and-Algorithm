#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		void EnQueue();
		void DeQueue();
		void display();
};
node *rear=NULL;
void node::EnQueue()
{
	
		
	if(rear==NULL)
	{
		rear=new node();
			cout<<"Enter data : ";
			cin>>rear->data;
	}
	else
	{
	static node *temp=rear;
	node *newnode;
	newnode=new node();
	cout<<"Enter data : ";
	cin>>newnode->data;
	newnode->next=NULL;
	temp->next=newnode;
	temp=temp->next;
	}
}

void node::DeQueue()
{
	if(rear==NULL)
	{
		cout<<"The Queue is Underflow!";
	}
	else
	{
	cout<<"Dequeued element is : "<<rear->data;
	rear=rear->next;
	}
}

void node::display()
{
	node* temp=rear;
	if(rear==NULL)
	{
		cout<<"\nThe Queue is Empty!\n";
	}
	else
	{
		while(temp!=NULL)
		{
		cout<<temp->data<<" ";
		temp=temp->next;
		}
	}
}
int main()
{
	node obj;
 int ch;
   
    while(ch!=4){
    	cout<<"\n1) Push in stack"<<endl;
   		cout<<"2) Pop from stack"<<endl;
   		cout<<"3) Display stack"<<endl;
  		cout<<"4) Exit"<<endl;
    	cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            obj.EnQueue();
            break;
         }
         case 2: {
            obj.DeQueue();
            break;
         }
         case 3: {
            obj.display();
            break;
         }
         case 4: {
            exit(0);
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
	
}
}
}
