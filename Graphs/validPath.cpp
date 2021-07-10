int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

bool inCircle(int i, int j, int r,vector<int> &A, vector<int> &B){
    for(int k = 0; k < A.size(); k++){
        if((A[k]-i)*(A[k]-i) + (B[k]-j)*(B[k]-j) <= r*r)
            return 1;
    }
 
    return 0;
}


// x           x,y 
// ^
// |
// |
// |
// |
// 0,0 -------->y

// i,x,row
// j,y,col

string Solution::solve(int x, int y, int N, int r, vector<int> &A, vector<int> &B) {
	vector<vector<bool>> vis(x+1,vector<bool> (y+1,0));
	queue<pair<int,int>> q;
	q.push({0,0});
	vis[0][0] = 1;

	while(!q.empty()){
		int i = q.front().first, j = q.front().second;
        q.pop();
		for(int k = 0; k < 8; k++){
			int  row = i + dx[k], col = j + dy[k];

			if(row >= 0 && row <= x && col >= 0 && col <= y){
				if(!vis[row][col] && !inCircle(row,col,r,A,B)){
					if(row == x && col == y)
						return "YES";

					vis[row][col] = 1;
					q.push({row,col});
				}
			}
		}
	}

	return "NO";

}
