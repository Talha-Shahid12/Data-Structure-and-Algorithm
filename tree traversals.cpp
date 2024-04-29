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