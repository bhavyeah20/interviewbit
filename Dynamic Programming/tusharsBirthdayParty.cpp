wt -> filling capacity of dish
val -> minCost
W -> capacity of friendd
int minCost(vector<int> wt, vector<int> val, int W) {
	int n = wt.size();
	int dp[n + 1][W + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < W + 1; j++)
		dp[0][j] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if (wt[i - 1] <= j)
				dp[i][j] = min(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];
}


int Solution::solve(const vector<int> &friendd, const vector<int> &capacity, const vector<int> &cost) {

	int total = 0;
	for (int i = 0; i < friendd.size(); i++) {
		total += minCost(capacity, cost, friendd[i]);
	}

	return total;

}