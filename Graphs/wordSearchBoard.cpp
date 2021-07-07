int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool dfs(vector<string> &A, int i, int j, int idx, string &B){
	if(idx == B.size())
		return 1;

	for(int k = 0; k < 4; k++){
		int x = i + dy[k], y = j + dx[k];
		if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size()){
			if(A[x][y] == B[idx]){
				if(dfs(A,x,y,idx+1,B)) return 1;
			}	
		}
	}
	//can memoize dp[i][j][idx]
	return 0;

}

int Solution::exist(vector<string> &A, string B) {
	int n = A.size(), m = A[0].size();
	int idx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] == B[idx]){
				if(dfs(A,i,j,idx+1,B))
					return 1;
			}
		}
	}

	return 0;
}
