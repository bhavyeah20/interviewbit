class Solution {
public:
    
    void build(int vertex,vector<int> &curr, vector<vector<int> > &path, vector<vector<int> > &graph ){
        
        if(vertex == graph.size() - 1){
            path.push_back(curr);
            return ;
        }
        for(int j = 0; j < graph[vertex].size(); j++){
            
            curr.push_back(graph[vertex][j]);
            build(graph[vertex][j],curr,path,graph);
                
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
     
        vector<vector<int>> path;
        vector<int> curr;
        curr.push_back(0);
        build(0,curr,path,graph);
        return path;
    }
};