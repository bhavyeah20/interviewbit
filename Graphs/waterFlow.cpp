int dx[4] = {0,1,0,-1}; 
int dy[4] = {1,0,-1,0};

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &A){
    vis[i][j] = 1;
    
    for(int k = 0; k < 4; k++){
    	int x = i + dx[k], y = j + dy[k];
    	if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size()){
    		if(!vis[x][y] && A[x][y] >= A[i][j])
    			dfs(x,y,vis,A);
    	}
    }
}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	vector<vector<bool>> b(n,vector<bool> (m,0));
	vector<vector<bool>> r(n,vector<bool> (m,0));
	int cnt = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!i && !b[i][j])
				dfs(i,j,b,A);

			if(!j && !b[i][j])
				dfs(i,j,b,A);
		
			if(i == n - 1 && !r[i][j])
				dfs(i,j,r,A);

			if(j == m - 1 && !r[i][j])
				dfs(i,j,r,A);

		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] && b[i][j]) cnt++;
		}
	}

	return cnt;

}
