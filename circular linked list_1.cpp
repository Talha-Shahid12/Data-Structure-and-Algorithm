#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
   
     void insertData();
     void printData();

};
node *head=0;
void node::insertData()
     {
     	int d;
        node *top;
        cout<<"Enter Data : ";
        cin>>d;
        head = new node();
        head->data=d;
		head->next=0;
		top=head;
       	 int c=0;
         cout<<"Do you want to continue If yes press 1 else press 2 : ";
            cin>>c;
            node *newnode;
        while(c==1)
        {
            cout<<"Enter Data : ";
            newnode=new node();
            cin>>newnode->data;
            newnode->next=0;
            top->next=newnode;
            top=top->next;
            cout<<"Do you want to continue If yes press 1 else press 2 : ";
            cin>>c;
            
        }
        newnode->next=head;
}

void node::printData()
     {
        node *top;
        top=head;
        while (top!=0)
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
