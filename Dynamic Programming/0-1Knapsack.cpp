int knapsack(vector<int> val, vector<int> wt, int w, int n) {
    int dp[1001][1001];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < w + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}


int Solution::solve(vector<int> &val, vector<int> &wt, int W) {
    return knapsack(val, wt, W, val.size());

}
