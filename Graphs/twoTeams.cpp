
    bool dfsHelper(int src, int color,vector<vector<int>> &graph, vector<int> &visited){
        visited[src] = color;
        
        for(auto nbr : graph[src]){
            if(!visited[nbr]){
                if(!dfsHelper(nbr,3-color,graph,visited))
                    return false;
            }
            
            else{
                if(visited[nbr] == color)
                    return false;
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> visited(n,0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(!dfsHelper(i,1,graph,visited))
                    return false;
            }
        }
        
        return true;
    }
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > graph(A);
    for(auto nodePair: B){
        int x = nodePair[0], y = nodePair[1];
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    
    return isBipartite(graph);
}
