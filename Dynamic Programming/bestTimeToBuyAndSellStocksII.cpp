int profit(int i, const vector<int> &A, bool buy, vector<vector<int> > &dp) {
	if (i == A.size())
		return 0;

	if (dp[buy][i] != -1)
		return dp[buy][i];

	int p = 0;
	if (buy) {
		for (int ii = i; ii < A.size(); ii++) {
			int curr1 = profit(ii + 1, A, 0, dp) - A[ii];
			int curr2 = profit(ii + 1, A, 1, dp);

			return dp[buy][i] = max({curr1, curr2, p});
		}
	} else {
		for (int ii = i; ii < A.size(); ii++) {
			int curr1 = profit(ii, A, 1, dp) + A[ii];
			int curr2 = profit(ii + 1, A, 0, dp);

			return dp[buy][i] = max({curr1, curr2, p});
		}
	}

}

int Solution::maxProfit(const vector<int> &A) {
	vector<vector<int> > dp(2, vector<int> (A.size(), -1));
	return profit(0, A, 1, dp);
}

//or
//greedy

int Solution::maxProfit(const vector<int> &A) {
	int profit = 0;

	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i + 1] > A[i])
			profit += A[i + 1] - A[i];
	}

	return profit;
}

