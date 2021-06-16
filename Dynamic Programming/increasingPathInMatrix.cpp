bool path(vector<vector<int> > &A, int i, int j, vector<vector<int> > &dp) {
	int n = A.size(), m = A[0].size();

	if (i == n - 1 && j == m - 1)
		return 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	bool path1 = 0, path2 = 0;

	if (i + 1 < n && A[i + 1][j] > A[i][j])
		path1 = path(A, i + 1, j, dp);

	if (j + 1 < m && A[i][j + 1] > A[i][j])
		path2 = path(A, i, j + 1, dp);

	return dp[i][j] = path1 || path2;
}


int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	vector<vector<int> > dp(n, vector<int> (m, -1));
	bool ans = path(A, 0, 0, dp);

	return ans == 0 ? -1 : n + m - 1;

}
