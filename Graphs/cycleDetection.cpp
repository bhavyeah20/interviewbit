#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"


class Graph{
	int V;
	list<int> *adjList;

public:
	Graph(int V){
		this->V = V;
		adjList = new list<int>[V];
	}

	void addEdge(int x, int y){
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	bool bfs(){
		queue<int> q;
		int *parent = new int[V];
		bool *visited = new bool[V];

		for(int i = 0; i < V; i++)
			parent[i] = i;

		for(int i = 0; i < V; i++)
			visited[i] = false;

		q.push(0);
		visited[0] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto child: adjList[node]){
				if(visited[child] && parent[node] != child)
					return true;

				else if(!visited[child]){
					visited[child] = true;
					parent[child] = node;
					q.push(child);
				}

			}
		}

		return false;
	}

	bool dfsHelper(int src, int parent, bool *visited){
		visited[src] = true;

		for(int child : adjList[src]){
			if(visited[child] && parent != child){
				return true;
			}

			else if(!visited[child]){
				parent = src;
				if(dfsHelper(child,parent,visited))
					return true;
			}
		}

		return false;
	}
		
	bool dfs(){
		bool *visited = new bool[V];
		int parent = 0;

		for(int i = 0; i < V; i++)
			visited[i] = false;
			
		return dfsHelper(0,parent,visited);

	}

};

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	cout<<g.dfs();

}

