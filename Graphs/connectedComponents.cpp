#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

template<typename T>

class Graph{
	map<T,vector<T>> adjList;

public:
	void addEdge(T x, T y){
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	void dfsHelper(T src,map<T,bool> &visited){
		cout<<src<<" ";
		visited[src] = true;

		for(auto child: adjList[src]){
			if(!visited[child]){
				dfsHelper(child,visited);
			}
		}

	}

	void dfs(){
		map<T,bool> visited;
		for(auto edge : adjList){
			T node = edge.first;
			visited[node] = false;
		}
		int cnt = 0;

		for(auto edge: adjList){
			T node = edge.first;
			if(!visited[node]){
				cout<<"Connected component "<<cnt<<" "<<endl;
				dfsHelper(node,visited);
				cnt++;
				cout<<endl;
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
	g.addEdge(2,5);
	g.addEdge(5,6);
	g.addEdge(5,7);
	g.addEdge(8,9);
	g.addEdge(8,10);
	g.addEdge(9,10);
	g.addEdge(11,12);




	g.dfs();

}

