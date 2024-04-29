#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node* right;
		node *left;
		node* newnode(int);
		node* insertData(node*, int);
		void preOrder(node*);
		void inOrder(node*);
		void postOrder(node*);
		node* minVal(node*);
		node* deleteNode(node*,int);
};
node* node::newnode(int d)
{
	node *newnode=new node();
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
node* node::insertData(node* root,int d)
{
	if(root==NULL)
	{
		return newnode(d);
	}
	
	if(d<root->data)
	{
		root->left=insertData(root->left,d);
	}
	
	else if(d>root->data)
	{
		root->right=insertData(root->right,d);
	}
	
	return root;
}

void node::preOrder(node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void node::inOrder(node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void node::postOrder(node* root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

node* node::minVal(node* root)
{
	while(root!=NULL && root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}


node* node::deleteNode(node* root, int d)
{
	if(root==NULL)
	{
		return root;
	}
	
		if(d<root->data)
		{
			root->left=deleteNode(root->left,d);
		}
		else if(d>root->data)
		{
			root->right=deleteNode(root->right,d);
		}
		else
		{
			if(root->left==NULL)
			{
				node* temp=root->right;
				free(root);
				return temp;
			}
			else if(root->right==NULL)
			{
				node* temp=root->left;
				free(root);
				return temp;
			}
			
			
			//node* temp=minVal(root->left);
			//root->data=temp->data;
			//root->left=deleteNode(root->left,temp->data);
			
		}
		
	return root;
}


int main()
{
	node ob;
	node *root = NULL;
  root = ob.insertData(root, 8);
  root = ob.insertData(root, 3);
  root = ob.insertData(root, 1);
  root = ob.insertData(root, 6);
  root = ob.insertData(root, 7);
  root = ob.insertData(root, 10);
  root = ob.insertData(root, 14);
  root = ob.insertData(root, 4);

  cout << "\nInorder traversal: ";
  ob.inOrder(root);
  
  node* min;
  min=ob.minVal(root);
  cout<<"\nminimum : "<<min->data;
  
  cout << "\nInorder traversal after delete 14 from Binary tree : ";
  ob.deleteNode(root,14);
  ob.inOrder(root);
  
  min=ob.minVal(root);
  cout<<"\nminimum : "<<min->data;
  
  cout << "\nPreOrder traversal: ";
  ob.preOrder(root);
  cout << "\nInOrder traversal: ";
  ob.inOrder(root);
  cout << "\nPostOrder traversal: ";
  ob.postOrder(root);
  
}
