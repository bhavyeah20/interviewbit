int cost(int i, int j, vector<vector<int>> &A, vector<vector<int> > &dp) {
	int m = A.size(), n = A[0].size();
	if (i == m - 1 && j == n - 1)
		return A[i][j];

	if (dp[i][j] != -1)
		return dp[i][j];

	int c1 = INT_MAX, c2 = INT_MAX;

	if (j + 1 < n)
		c1 = cost(i, j + 1, A, dp);

	if (i + 1 < m)
		c2 = cost(i + 1, j, A, dp);

	return dp[i][j] = A[i][j] + min(c1, c2);


}

int Solution::minPathSum(vector<vector<int> > &A) {
	int m = A.size();
	int n = A[0].size();
	vector<vector<int> > dp(m, vector<int> (n, -1));
	return cost(0, 0, A, dp);

}

//or

int Solution::minPathSum(vector<vector<int> > &A) {
	int m = A.size();
	int n = A[0].size();
	vector<vector<int> > dp(m, vector<int> (n, 0));

	dp[m - 1][n - 1] = A[m - 1][n - 1];

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == m - 1 && j == n - 1)
				continue;

			int c1 = INT_MAX, c2 = INT_MAX;

			if (j + 1 < n)
				c1 = dp[i][j + 1];

			if (i + 1 < m)
				c2 = dp[i + 1][j];

			dp[i][j] = A[i][j] + min(c1, c2);
		}
	}

	return dp[0][0];

}

// or

int Solution::minPathSum(vector<vector<int> > &A) {
	int m = A.size();
	int n = A[0].size();
	vector<vector<int> > dp(2, vector<int> (n, 0));

	dp[0][n - 1] = A[m - 1][n - 1];

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == m - 1 && j == n - 1)
				continue;

			int c1 = INT_MAX, c2 = INT_MAX;

			if (j + 1 < n)
				c1 = dp[0][j + 1];

			if (i + 1 < m)
				c2 = dp[1][j];

			dp[0][j] = A[i][j] + min(c1, c2);
		}

		dp[1] = dp[0];
	}

	return dp[1][0];

}
