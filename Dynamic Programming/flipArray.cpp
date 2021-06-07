int Solution::solve(const vector<int> &wt) {
	int sum = 0;
	for (int x : wt)
		sum += x;

	int n = wt.size();
	// bool dp[n + 1][sum + 1];

	// for (int j = 0; j < sum + 1; j++)
	//     dp[0][j] = 0;

	// for (int i = 0; i < n + 1; i++)
	//     dp[i][0] = 1;


	// for (int i = 1; i < n + 1; i++) {
	//     for (int j = 1; j < sum + 1; j++) {
	//         if (wt[i - 1] <= j)
	//             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - wt[i - 1]];

	//         else
	//             dp[i][j] = dp[i - 1][j];
	//     }
	// }

	// int i;
	// for (i = sum / 2; i >= 0; i--) {
	//     if (dp[n][i])
	//         break;
	// }

	// sum = i;


	// No need as dp[i][j] will be INT_MAX - 1 if j is not achievable
	sum /= 2;

	int dp2[n + 1][sum + 1];

	for (int j = 0; j < sum + 1; j++)
		dp2[0][j] = INT_MAX - 1;

	for (int i = 0; i < n + 1; i++)
		dp2[i][0] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (wt[i - 1] <= j)
				dp2[i][j] = min(dp2[i - 1][j], 1 + dp2[i - 1][j - wt[i - 1]]);

			else
				dp2[i][j] = dp2[i - 1][j];
		}
	}
	int j = sum;
	while (dp2[n][j] == INT_MAX - 1)
		j--;

	return dp2[n][j];

}
