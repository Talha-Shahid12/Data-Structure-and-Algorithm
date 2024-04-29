#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include<queue>
using namespace std;
class Graph{
	public:
		int v;
		void insertEdge(int,int);
		list<int> *l;
		Graph(int);
		void DFS(int);
		void BFS(int);
};
	
Graph::Graph(int v)
{
	this->v=v;
	l=new list<int>[v];
}

void Graph::insertEdge(int u,int w)
{
	l[u].push_back(w);
}


void Graph::DFS(int source)
{
	
	stack<int> s;
	bool* visited;
	visited= new bool[v];
	
	for(int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	
	visited[source]=true;
	s.push(source);
	
	list<int>::iterator i;
	
	while(!s.empty())
	{
		source=s.top();
		cout<<source<<" ";
		s.pop();
		for(i=l[source].begin(); i!=l[source].end(); i++)
		{
			if(!visited[*i]){
				visited[*i]=true;
				s.push(*i);
			}
		}
	}
	
	
}





void Graph::BFS(int source)
{
	bool* visited;
	visited= new bool[v];
	for(int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	queue<int> q;
	visited[source]=true;
	q.push(source);
	
	list<int>::iterator i;
	 while(!q.empty())
	 {
	 	source=q.front();
	 	cout<<source<<" ";
	 	q.pop();
	 	
	 	for(i=l[source].begin(); i!=l[source].end(); i++)
	 	{
	 		if(!visited[*i])
	 		{
	 			visited[*i]=true;
	 			q.push(*i);
			 }
		 }
	 	
	 }
	
}








 int main()
 {
 	
 	Graph ob(10);
 	ob.insertEdge(0, 1);
    ob.insertEdge(0, 2);
    ob.insertEdge(0, 3);
    ob.insertEdge(1, 4);
    ob.insertEdge(2, 5);
    ob.insertEdge(3, 6);
    ob.insertEdge(4, 7);
    ob.insertEdge(5, 8);
    ob.insertEdge(6, 9);
    ob.insertEdge(7, 0);
 	ob.DFS(1);
 	
 	
 }
