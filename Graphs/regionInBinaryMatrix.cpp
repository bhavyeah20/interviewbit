int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<bool>> vis(n, vector<bool> (m,0));
    int ans = 0, curr = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && A[i][j] == 1){
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                curr = 1;
                while(!q.empty()){
                    int y = q.front().first, x = q.front().second;
                    q.pop();
                    
                    vector<int> dy({1,1,0,-1,-1,-1,0,1});
                    vector<int> dx({0,1,1,1,0,-1,-1,-1});
                    
                    for(int k = 0; k < 8; k++){
                        if(x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n){
                            if(!vis[y+dy[k]][x+dx[k]] && A[y+dy[k]][x+dx[k]] == 1){
                                vis[y+dy[k]][x+dx[k]] = 1;
                                q.push({y+dy[k],x+dx[k]});
                                curr++;
                            }
                        }
                    }
                    
                }
                
                ans = max(ans,curr);
            }
        }
    }
    
    return ans;
}

//or


class Solution {
public:
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
            
    int regionMax(int y, int x,vector<vector<int>> &A){
        int n = A.size(), m = A[0].size();
        A[y][x] = -1;
        int cnt = 1;

        for(int k = 0; k < 4; k++){
            if(x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n){
                if(A[y+dy[k]][x+dx[k]] == 1){
                    cnt += regionMax(y + dy[k], x + dx[k],A);
                }
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& A) {
        
        int n = A.size(), m = A[0].size();
        int ans = 0, curr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i][j] == 1){
                    ans = max(ans, regionMax(i,j,A));
                }

 
            }
        }
        
        return ans;
    }

};