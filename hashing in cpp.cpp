#include<iostream>
using namespace std;

#define size 10

class Entry{
	public:
		int key;
		int data;
		Entry(int key, int data)
		{
			this->key=key;
			this->data=data;
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
		int newHash;
		for(int i=0; i<size; i++)
		{
			newHash=HashFunction(hash+i);
			if(table[newHash]==NULL)
			{
			table[newHash]=e;
			cout<<"\n\nElement inserted at index "<<newHash;
			break;
			}
		}
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
	 if(table[hash]->key==k)
		{
				cout<<endl<<table[hash]->data<<" Found at "<<hash<<endl;
		}
	   else
		{
		int newHash;
		for(int i=0; i<size; i++)
		{
			newHash=HashFunction(hash+i);
			if(table[newHash]==NULL)
			{
				cout<<"\n\nNot Found\n";
				break;
			}
			else if(table[newHash]->key==k)
			{
				cout<<endl<<table[newHash]->data<<" Found at "<<newHash<<endl;
				break;
			}
		}
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
	else if(table[hash]->key==k)
		{
			delete table[hash];
			table[hash]=NULL;
			cout<<"\nDeleted!\n";
		}
		
		else
		{
			int newHash;
			for(int i=0; i<size; i++)
			{
				newHash=HashFunction(hash+i);
				if(table[newHash]==NULL)
				{
					cout<<"\nNot Exists!\n";
					break;
				}
				if(table[newHash]->key=k)
				{
					delete table[newHash];
					table[newHash]=NULL;
					cout<<"\nDeleted!\n";
					break;
				}
			}
		}
		
	}


int main()
{
	Hashing ob;
	ob.insertData(2, 10);
	ob.insertData(12, 20);
	ob.insertData(22, 30);
	ob.searchData(23);
	ob.searchData(22);
	ob.remove(22);
}
