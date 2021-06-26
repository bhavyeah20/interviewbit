bool dfs(int sv, int t, vector<bool> &visited,unordered_map<int,vector<int>> &mp){
	if(sv == t)
		return 1;

	visited[sv] = 1;

	for(int i = 0; i < mp[sv].size(); i++){
	    
		if(!visited[mp[sv][i]] && dfs(mp[sv][i],t,visited,mp))
			return 1;
	}
    
	visited[sv] = 0;
	return 0;


}

int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<int>> mp;
	for(int i = 0; i < B.size(); i++){
		mp[B[i][0]].push_back(B[i][1]);
	}

	vector<bool> visited(A+1,0);
	return dfs(1,A,visited,mp);
}

//or

bool bfs(int sv, int t, vector<bool> &visited,unordered_map<int,vector<int>> &mp){
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == t)
            return 1;
        for(int i = 0; i < mp[v].size(); i++){
            if(!visited[mp[v][i]]){
                q.push(mp[v][i]);
                visited[mp[v][i]] = 1;
            }
        }
    }
    
    return 0;


}

int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int,vector<int>> mp;
    for(int i = 0; i < B.size(); i++){
        mp[B[i][0]].push_back(B[i][1]);
    }

    vector<bool> visited(A+1,0);
    return bfs(1,A,visited,mp);
}
