class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int src, vector<bool> &visited, list<int> &order, vector<int> graph[]){
        visited[src] = 1;
        
        for(int i = 0; i < graph[src].size(); i++){
            if(!visited[graph[src][i]]){
                dfs(graph[src][i],visited,order,graph);
            }
        }
        
        order.push_front(src);
    }
    
    void dfs2(int src, vector<bool> &visited, vector<int> rev[]){
        visited[src] = 1;
        
        for(int i = 0; i < rev[src].size(); i++){
            if(!visited[rev[src][i]]){
                dfs2(rev[src][i],visited,rev);
            }
        }
        
    }
    
    int kosaraju(int V, vector<int> graph[])
    {
        //code here
        vector<int> rev[V];
        vector<bool> visited(V,0);
        
        for(int i = 0; i < V; i++){
            for(int j = 0; j < graph[i].size(); j++)
                rev[graph[i][j]].push_back(i);
        }
        
        list<int> order;
        for(int i = 0; i < V; i++){
            if(!visited[i])
                dfs(i,visited,order,graph);
        }
        
        for(int i = 0; i < V; i++)
            visited[i] = 0;
        
        int cnt = 0;
        for(auto node : order){
            if(!visited[node]){
                cnt++;
                dfs2(node,visited,rev);
            }
        }
        
        return cnt;
    }
};