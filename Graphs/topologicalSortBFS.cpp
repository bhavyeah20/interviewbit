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
	}

	void bfs(){
		queue<int> q;
		int *indegree = new int[V];

		for(int i = 0; i < V; i++)
			indegree[i] = 0;

		for(int i = 0; i < V; i++){
			for(auto node : adjList[i]){
				indegree[node]++;
			}
		}

		for(int i = 0; i < V; i++){
			if(!indegree[i])
				q.push(i);
		}

		while(!q.empty()){
			int root = q.front();
			q.pop();
			cout<<root<<" ";

			for(auto node: adjList[root]){
				indegree[node]--;

				if(!indegree[node])
					q.push(node);
			}
		}
	}
	

};

int main(){
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(0,2);

	g.bfs();

}

