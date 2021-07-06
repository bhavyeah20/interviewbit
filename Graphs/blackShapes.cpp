int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(vector<string> &A, int i, int j){
	A[i][j] = 'O';

	for(int k = 0; k < 4; k++){
		if(i+dy[k] >= 0 && i+dy[k] < A.size() && j+dx[k] >= 0 && j+dx[k] < A[0].size()){
			if(A[i+dy[k]][j+dx[k]] == 'X'){
				dfs(A,i+dy[k],j+dx[k]);
			}
		}
	}
}

int Solution::black(vector<string> &A) {
	int n = A.size();
	int m = A[0].size();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] == 'X'){
				cnt++;
				dfs(A,i,j);
			}
		}
	}

	return cnt;
}
