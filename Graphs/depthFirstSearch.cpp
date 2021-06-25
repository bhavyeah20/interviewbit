#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

void printDFS(int **edges, int n, int startingVertex, bool *visited){

	cout<<startingVertex<<" ";
	visited[startingVertex] = 1;

	for(int i = 0; i < n; i++){
		if(i == startingVertex)
			continue;

		if(edges[startingVertex][i] && !visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
}

int main(){
	int n,e;
	cout<<"Enter number of vertices "<<endl;
	cin >> n;
	cout<<"Enter number of edges "<<endl;
	cin >> e;

	cout<<"Enter edges "<<endl;
	int **edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		edges[f][s] = edges[s][f] = 1;
	}

	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	
	for(int i = 0; i < n; i++){
		if(!visited[i])
			print(edges,n,i,visited);
	}

}

