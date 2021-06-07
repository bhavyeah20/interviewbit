int Solution::minDistance(string A, string B) {
	int n = A.size(), m = B.size();

	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = i;


	for (int j = 0; j < m + 1; j++)
		dp[0][j] = j;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(1 + dp[i][j - 1], min(1 + dp[i - 1][j - 1], 1 + dp[i - 1][j]));
			}
		}
	}

	return dp[n][m];

}
