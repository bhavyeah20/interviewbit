int minCost(vector<int> wt, vector<int> val, int W, vector<int> friendd) {
	int n = wt.size();
	int dp[n + 1][W + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < W + 1; j++)
		dp[0][j] = 1000000;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if (wt[i - 1] <= j)
				dp[i][j] = min(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	int total = 0;
	for (int x : friendd)
		total += dp[n][x];

	return total;
}


int Solution::solve(const vector<int> &friendd, const vector<int> &capacity, const vector<int> &cost) {

	int total = 0;
	int W = *max_element(friendd.begin(), friendd.end());

	return minCost(capacity, cost, W, friendd);


}