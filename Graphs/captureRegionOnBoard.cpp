int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &A){

    vis[i][j] = 1;   

    if(A[i][j] == 'X'){
        return;
    }

    A[i][j] = '#';

    for(int k = 0; k < 4; k++){
        if(i+dy[k] >= 0 && i+dy[k] < vis.size() && j+dx[k] >= 0 && j+dx[k] < vis[0].size()){
            if(!vis[i+dy[k]][j+dx[k]]){
                dfs(i+dy[k],j+dx[k],vis,A);
            }
        }
    }

}

void Solution::solve(vector<vector<char> > &A) {

    int n = A.size(), m = A[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m,0));

    for(int i = 0; i < n; i++){
        if(!vis[i][0]){
            dfs(i,0,vis,A);
        }    
        if(!vis[i][m-1]){
            dfs(i,m-1,vis,A);
        }
    }

    for(int j = 0; j < m; j++){
        if(!vis[0][j])
            dfs(0,j,vis,A);

        if(!vis[n-1][j])
            dfs(n-1,j,vis,A);
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            A[i][j] = A[i][j] == '#' ? 'O' : 'X';
        }
    }
}
