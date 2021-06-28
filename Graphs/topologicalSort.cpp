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
	}

	void dfsHelper(T src,map<T,bool> &visited,list<T> &order){
		// cout<<src<<" ";
		visited[src] = true;

		for(auto child: adjList[src]){
			if(!visited[child]){
				dfsHelper(child,visited,order);
			}
		}

		order.push_front(src);

	}

	void dfs(){
		map<T,bool> visited;
		list<T> order;
		for(auto edge : adjList){
			T node = edge.first;
			visited[node] = false;
		}

		for(auto edge: adjList){
			T node = edge.first;
			if(!visited[node])
				dfsHelper(node,visited,order);
		}

		for(auto it: order)
			cout<<it<<endl;
	}


};

int main(){
	Graph<string> g;
	g.addEdge("Python","Data preprocessing");
	g.addEdge("Python","Pytorch");
	g.addEdge("Python","ML");
	g.addEdge("Data preprocessing","ML");
	g.addEdge("ML","DL");
	g.addEdge("Pytorch","DL");
	g.addEdge("DL","Face recog");
	g.addEdge("Data","Face recog");

	g.dfs();

}

