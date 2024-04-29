#include<iostream>
using namespace std;

#define size 10

class Entry{
	public:
		int key;
		int data;
		Entry *next;
		Entry(int key, int data)
		{
			this->key=key;
			this->data=data;
			next=NULL;
			}	
};


class Hashing{
		Entry **table;
	public:
		int HashFunction(int);
		void insertData(int,int);
		void searchData(int);
		void remove(int);
		Hashing(){
			table=new Entry*[size];
			for(int i=0; i<size; i++)
			{
				table[i]=NULL;
			}
		}
		
	
		
};

int Hashing::HashFunction(int key)
{
	return (key%size);
}

void Hashing::insertData(int k, int d)
{
	int hash=HashFunction(k);
	Entry *e=new Entry(k,d);
	if(table[hash]==NULL)
	{
		table[hash]=e;
		cout<<"\n\nElement inserted at index "<<hash;
	}
	else
	{
		Entry* temp=table[hash];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	
		temp->next=e;
		cout<<"\n\nElement inserted at index "<<hash;
	}
}

void Hashing::searchData(int k)
{
	int hash=HashFunction(k);
	if(table[hash]==NULL)
	{
		cout<<"\n\nNot Found!\n\n"<<endl;
	}
	else
	{
		Entry* temp=table[hash];
		while(temp!=NULL && temp->key!=k)
		{
			temp=temp->next;
		}
		if(temp==NULL)
		{
			cout<<"\n\nNot Found\n";
		}
		else
		{
			cout<<endl<<"data : "<<temp->data<<", key "<<temp->key<<endl;	
		}

	}
}
	



void Hashing::remove(int k)
{
	int hash=HashFunction(k);
	if(table[hash]==NULL)
	{
		cout<<"Not Exists"<<endl;
	}
		else
		{
			if(table[hash]->key==k)
			{
				Entry* temp=table[hash];
				table[hash]=table[hash]->next;
				delete temp;
				cout<<"\n\ndeleted!\n\n";
			}
			else
			{
			Entry* prev=NULL;
			Entry* temp=table[hash];
			while(temp!=NULL && temp->key!=k)
			{
				prev=temp;
				temp=temp->next;
			}
			if(temp==NULL)
			{
				cout<<"\nKey Not Exists!"<<endl;
			}
			else
			{
				cout<<"\n\n"<<temp->data<<" deleted";
				 prev->next=temp->next;
				delete temp;
			}
			}
		}
		
	}


int main()
{
    Hashing table;
    table.insertData(2, 10);
    table.insertData(12, 20);
    table.remove(12);
    table.searchData(12);
}
