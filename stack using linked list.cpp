#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		void push();
		void pop();
		void display();
};
node *top=NULL;
void node::push()
{
	node* newnode;
	newnode=new node();
	cout<<"Enter data : ";
	cin>>newnode->data;
	newnode->next=top;
	top=newnode;
}
void node::pop()
{
	if(top==NULL)
	{
		cout<<"Stack underflow!";
	}
	else
	{
		cout<<"poped element is : "<<top->data;
		top=top->next;
	}
}

void node::display()
{
	node *temp=top;
	if(temp==NULL)
	{
		cout<<"\nThe Stack is Empty!\n";
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
            obj.push();
            break;
         }
         case 2: {
            obj.pop();
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


