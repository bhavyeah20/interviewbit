int LCS(string x, string y, int n, int m) {
	if (m == 0 || n == 0)
		return 0;

	if (x[n - 1] == y[m - 1])
		return 1 + LCS(x, y, n - 1, m - 1);

	else
		return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
}

// int dp[1001][1001];
// memset(dp, -1, sizeof(dp));

// or

// int **dp = new int *[n + 1];

// for (int i = 0; i < n + 1; i++)
// 	dp[i] = new int [m + 1];

// for (int i = 0; i < n + 1; i++)
// 	for (int j = 0; j < m + 1; j++) dp[i][j] = -1;


int LCSMemoized(string x, string y, int n, int m) {

	if (n == 0 || m == 0)
		return 0;

	if (dp[n][m] == -1) {
		if (x[n - 1] == y[m - 1])
			dp[n][m] = 1 + LCSMemoized(x, y, n - 1, m - 1);

		else
			dp[n][m] = max(LCSMemoized(x, y, n, m - 1), LCSMemoized(x, y, n - 1, m));
	}

	return dp[n][m];
}



int LCStabular(string x, string y, int n, int m) {

	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < m + 1; j++)
		dp[0][j] = 0;


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

		}
	}

	return dp[n][m];
}
