//Memo + O(n^2)

int cost(int i, int j, vector<vector<int> > &A, vector<vector<int> > &dp) {
	int n = A.size();

	if (i == n)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = A[i][j] + max(cost(i + 1, j, A, dp), cost(i + 1, j + 1, A, dp));

}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > dp(n, vector<int> (n, -1));
	return cost(0, 0, A, dp);
}

// or
//Tabular + O(n^2)


int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > dp(n, vector<int> (n, 0));


	for (int j = 0; j < n; j++)
		dp[n - 1][j] = A[n - 1][j];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	return dp[0][0];
}

// or
//Tabular + O(2n)


int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<vector<int> > dp(2, vector<int> (n, 0));


	for (int j = 0; j < n; j++)
		dp[1][j] = A[n - 1][j];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[0][j] = A[i][j] + max(dp[1][j], dp[1][j + 1]);
		}

		dp[1] = dp[0];
	}

	return dp[1][0];
}


// or
//Tabular + O(n)


int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<int> dp(n);


	for (int j = 0; j < n; j++)
		dp[j] = A[n - 1][j];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[j] = A[i][j] + max(dp[j], dp[j + 1]);
		}

	}

	return dp[0];
}