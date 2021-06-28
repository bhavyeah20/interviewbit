bool dfsHelper(int src, unordered_map<int, vector<int>> &adjList, vector<bool> &visited,
                 vector<int> &path){
    visited[src] = 1;
    path[src] = 1;
    
    for(auto child : adjList[src]){
        if(visited[child] && path[child])
            return 1;
            
        else if(!visited[child]){
            if(dfsHelper(child,adjList,visited,path))
                return 1;
        }
    }
    
    path[src] = 0;
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int> > adjList;
    for(int i = 0; i < B.size(); i++){
        adjList[B[i][0]].push_back(B[i][1]);
    }
    
    vector<bool> visited(A+1,0);
    vector<int> path(A+1,0);
    for(int i = 1; i <= A; i++){
        if(!visited[i]){
            if(dfsHelper(i,adjList,visited,path))
                return 1;
        }
    }
    
    return 0;
}




// Kahns Algo(TopoSort bfs)
// if order.size() != #vertices --> cycle present