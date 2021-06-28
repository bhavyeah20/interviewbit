#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

template<typename T>

class Graph{
	unordered_map<T,vector<T>> adjList;

public:
	void addEdge(T x, T y){
		adjList[x].push_back(y);
	}

	void dfsHelper(T src,unordered_map<T,bool> &visited){
		cout<<src<<" ";
		visited[src] = true;

		for(auto child: adjList[src]){
			if(!visited[child]){
				dfsHelper(child,visited);
			}
		}


	}

	void dfs(T src){
		unordered_map<T,bool> visited;
		for(auto edge : adjList){
			T node = edge.first;
			visited[node] = false;
		}

		dfsHelper(src,visited);
	}

	void bfs(T src){
		unordered_map<T,bool> visited;
		for(auto edge : adjList){
			T node = edge.first;
			visited[node] = false;
		}
		queue<T> q;
		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" ";

			for(auto child: adjList[node]){
				if(!visited[child]){
					visited[child] = true;
					q.push(child);
				}
			}
		}
	}


};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(2,6);
	g.addEdge(5,7);
	g.addEdge(6,7);

	g.bfs(0);

}

