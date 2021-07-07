int dx[8] = {2,2,1,-1,-2,-2,1,-1};
int dy[8] = {1,-1,-2,-2,1,-1,2,2};

bool inBound(int x, int y, int A, int B){
	return x >= 1 && y >= 1 && x <= A && y <= B;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
	vector<vector<bool>> vis(A+1,vector<bool> (B+1,0));
	queue<pair<int,int>> q;
	q.push({C,D});
	vis[C][D] = 1;
	if(C == E && D == F) return 0;
	int moves = 0;
	while(!q.empty()){
	    moves++;
	    int sz = q.size();
		for(int i = 0; i < sz; i++){
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			for(int k = 0; k < 8; k++){
				if(inBound(x+dx[k],y+dy[k],A,B) && !vis[x+dx[k]][y+dy[k]]){
					q.push({x+dx[k],y+dy[k]});
					vis[x+dx[k]][y+dy[k]] = 1;
					
				if(x+dx[k] == E && y+dy[k] == F)
				    return moves;
				}
			}
		}
	}
	return -1;
}
