int Solution::solve(vector<int> &A) {
    int n = A.size();
    int t = 0;
    for (int i = 0; i < n; i++)
        t += A[i];


    bool dp[n + 1][t + 1];

    for (int j = 0; j < t + 1; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < t + 1; j++) {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int minn = INT_MAX;
    for (int j = 0; j <= t / 2; j++) {
        minn = min(minn, t - 2 * ((dp[n][j]) ? j : 0));
    }

    return minn;
}
