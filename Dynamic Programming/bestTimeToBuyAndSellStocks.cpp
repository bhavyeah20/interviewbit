int Solution::maxProfit(const vector<int> &A) {
	int n = A.size();
	vector<int> suffix(n, A[n - 1]);

	for (int i = n - 2; i >= 0; i--)
		suffix[i] = max(suffix[i + 1], A[i]);

	int profit = 0;

	for (int i = 0; i < n; i++) {
		profit = max(profit, suffix[i] - A[i]);
	}

	return profit;
}
