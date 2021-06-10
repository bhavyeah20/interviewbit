int cost(int i, int runningColor, vector<vector<int>> &A, vector<vector<int>> &dp) {
	int n = A.size();
	if (i == n)
		return 0;


	if (dp[i][runningColor] != -1)
		return dp[i][runningColor];

	int c0, c1, c2;

	if (runningColor == 0) {
		c1 = cost(i + 1, 1, A, dp) + A[i][0];
		c2 = cost(i + 1, 2, A, dp) + A[i][0];

		return dp[i][runningColor] = min(c1, c2);
	}

	if (runningColor == 1) {
		c0 = cost(i + 1, 0, A, dp) + A[i][1];
		c2 = cost(i + 1, 2, A, dp) + A[i][1];

		return dp[i][runningColor] = min(c0, c2);
	}


	if (runningColor == 2) {
		c0 = cost(i + 1, 0, A, dp) + A[i][2];
		c1 = cost(i + 1, 1, A, dp) + A[i][2];

		return dp[i][runningColor] = min(c0, c1);
	}

}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > dp(n, vector<int> (3, -1));
	return min(cost(0, 0, A, dp), min(cost(0, 1, A, dp), cost(0, 2, A, dp)));
}
