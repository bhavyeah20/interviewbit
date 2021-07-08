int dfs(int src, int curr, vector<bool> &vis, vector<int> &A, int C,unordered_map<int,vector<int>> &l){
	int cnt = 0; // number of good paths
	bool leaf = 1;
	vis[src] = 1;
	if(A[src] == 1)
		curr++; // count of good nodes

	if(curr > C)
		return 0;

	for(auto nbr: l[src]){
		if(!vis[nbr]){
			leaf = 0;
			cnt += dfs(nbr,curr,vis,A,C,l);
		}
	}

	if(leaf) return 1;
	
	return cnt;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
	int V = A.size();
	unordered_map<int,vector<int>> l(V);

	for(auto it: B){
		l[it[0]-1].push_back(it[1]-1);
		l[it[1]-1].push_back(it[0]-1);
	}

	vector<bool> vis(V,0);
	return dfs(0,0,vis,A,C,l);
}
