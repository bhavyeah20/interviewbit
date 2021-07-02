class Solution {
public:
    
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
};

//or

class Solution {
public:
    
    bool bfsHelper(int src, int color,vector<vector<int>> &graph, vector<int> &visited){
        queue<int> q;
        q.push(src);
        visited[src] = color;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int clr = visited[node];
            
            for(auto nbr : graph[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 3 - clr;
                }

                else{
                    if(visited[nbr] == clr)
                        return false;
                }
            }
        }
 
            
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> visited(n,0);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(!bfsHelper(i,1,graph,visited))
                    return false;
            }
        }
        
        return true;
    }
};