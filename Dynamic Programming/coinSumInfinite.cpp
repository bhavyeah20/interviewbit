int Solution::coinchange2(vector<int> &coin, int t) {

	int n = coin.size();

	int dp[n + 1][t + 1];


	for (int j = 0; j < t + 1; j++)
		dp[0][j] = 0;
	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < t + 1; j++) {
			if (coin[i - 1] <= j)
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][t];

}


int Solution::coinchange2(vector<int> &coins, int t) {
	int mod = 1000007;
	int n = coins.size();
	int dp[t + 1];
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;

	for (int coin : coins) {
		for (int j = coin; j < t + 1; j++) {
			dp[j] += dp[j - coin] % mod;
		}
	}

	return dp[t] % mod;

}
