#include<iostream>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n)
{
	int minVertex=-1;
	
	for(int i=0; i<n; i++)
	{
		if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
		{
			minVertex=i;
		}
	}
	
	return minVertex;
}

void Prims(int** edges, int n){
	int *distance;
	bool *visited;
	int *parent;
	distance=new int[n];
	visited=new bool[n];
	parent=new int[n];
	
	for(int i=0; i<n; i++)
	{
		visited[i]=false;
		distance[i]=INT_MAX;
	}
	
	distance[0]=0;
	
	for(int i=0; i<n; i++)
	{
		int minVertex=findMinVertex(distance,visited,n);
		visited[minVertex]=true;
		
		for(int j=0; j<n; j++)
		{
			if(!visited[j] && edges[minVertex][j]!=0)
			{
				if(edges[minVertex][j] < distance[j])
				{
					distance[j]=edges[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
		
	}
	
	
		for(int i=1; i<n; i++)
		{
			if(parent[i]<i)
			{
			cout<<parent[i]<<" "<<i<<" "<<distance[i]<<endl;
			}
			else
			{
				cout<<i<<" "<<parent[i]<<" "<<distance[i]<<endl;
			}
		}
	
}
int main()
{
	int n,e;
	cin>>n;
	cin>>e; 
	int **edges= new int*[n];
	
	for(int i=0; i<n; i++)
	{
		edges[i]=new int[n];
		for(int j=0; j<n; j++)
		{
			edges[i][j]=0;
		}
	}
	
	
	for(int i=0; i<e; i++)
	{
		int f,s,weight;
		cin>>f>>s>>weight;
		edges[f][s]=weight;
		edges[s][f]=weight;
	}
	
	cout<<endl;
	
	Prims(edges,n);
	
	for(int i=0; i<n; i++)
	{
		delete[] edges[i];
	}
	
	delete[] edges;
	
	return 0;
}
