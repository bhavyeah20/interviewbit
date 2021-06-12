int cost(int i, int j, vector<vector<int> > &A, vector<vector<int> > &dp) {
    int n = A.size();

    if (i == n)
        return 0;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = A[i][j] + min(cost(i + 1, j, A, dp), cost(i + 1, j + 1, A, dp));
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > dp(n, vector<int> (n, -1));
    return cost(0, 0, A, dp);
}

// or


int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> dp(n, 0);

    for (int j = 0; j < n; j++)
        dp[j] = A[n - 1][j];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < A[i].size(); j++) {
            dp[j] = A[i][j] + max(dp[j], dp[j + 1]);
        }

    }

    return dp[0];
}