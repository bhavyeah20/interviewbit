int LIS(int prevIdx, int i, vector<vector<int> > &A, vector<vector<int> > &dp) {
	int n = A.size();
	if (i == n)
		return 0;

	if (prevIdx != n + 1 && dp[prevIdx][i] != -1)
		return dp[prevIdx][i];

	int len1 = 0, len2 = 0;
	if (prevIdx == n + 1 || A[i][0] > A[prevIdx][1]) {
		len1 =  1 + LIS(i, i + 1, A, dp);
	}

	len2 =  LIS(prevIdx, i + 1, A, dp);

	return dp[prevIdx][i] = max(len1, len2);
}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > dp(n + 2, vector<int> (n + 2, -1));

	return LIS(n + 1, 0, A, dp);
}
