int LCStabular(string x, int n) {

	int dp[n + 1][n + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < n + 1; j++)
		dp[0][j] = 0;


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (x[i - 1] == x[j - 1] && i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

		}
	}

	return dp[n][n];
}
