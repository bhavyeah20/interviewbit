#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

void SSSP(int startingVertex, int N, unordered_map<int,vector<int>> &adjList){
	vector<int> distance(N,-1);
	queue<int> q;
	q.push(startingVertex);
	distance[startingVertex] = 0;

	while(!q.empty()){
		int vtx = q.front();
		q.pop();

		for(auto child: adjList[vtx]){
			if(distance[child] == -1){
				q.push(child);
				distance[child] = distance[vtx] + 1;
			}
		}
	}

	for(int i = 0; i < N; i++)
		cout<<"Distance of node "<<i<<"from "<<startingVertex<<" "<<distance[i]<<endl;

}
int main(){

	int N;
	cout<<"Enter number of vertices "<<endl;
	cin >> N;

	unordered_map<int,vector<int> > adjList;
	cout<<"Enter number of edges "<<endl;
	int e;
	cin >> e;

	cout<<"Enter edges "<<endl;
	
	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
	}

	SSSP(0,N,adjList);

}

