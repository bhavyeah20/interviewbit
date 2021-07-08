bool cycle(int src, vector<bool> &vis, vector<bool> &path, vector<vector<int>> &adjList){
	vis[src] = 1;
	path[src] = 1;

	for(auto nbr : adjList[src]){
		if(vis[nbr] && path[nbr])
			return 1;

		else if(!vis[nbr]){
			if(cycle(nbr,vis,path,adjList))
				return 1;
		}
	}

	path[src] = 0;
	return 0;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
	vector<vector<int>> adjList(A+1);
	vector<bool> vis(A+1,0), path(A+1,0);
	for(int i = 0; i < B.size(); i++){
		adjList[B[i]].push_back(C[i]);
	}

	if(cycle(1,vis,path,adjList))
		return 0;

	return 1;
}
