#include<bits/stdc++.h>

using namespace std;

bool dfsHelper(int node, vector<bool> &visited, int parent, unordered_map<int, vector<int>> &adjList){
    visited[node] = 1;
    
        
    for(int child: adjList[node]){
        if(visited[child] && parent!= child)
            return 1;
            
        else if(!visited[child]){
            parent = node;
            if(dfsHelper(child, visited, parent, adjList))
                return 1;
        }
        
    }
    
    return 0;
}

int solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int> > adjList;
    for(int i = 0; i < B.size(); i++){
        adjList[B[i][0]].push_back(B[i][1]);
        adjList[B[i][1]].push_back(B[i][0]);   
    }
    
    vector<bool> visited(A+1,0);
    
    for(int i = 1; i <= A; i++){
        if(!visited[i]){
            if(dfsHelper(i,visited,-1,adjList))
                return 1;
        }
    }
    
    return 0;
}

int main(){
	vector<vector<int> > B({{1,3},{1,2},{4,5}});
	cout<<solve(5,B);
}