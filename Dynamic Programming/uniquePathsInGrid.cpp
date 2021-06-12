int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

	int m = A.size(), n = A[0].size();

	vector<vector<int> > dp(m, vector<int> (n, 0));

	for (int j = n - 1; j >= 0; j--) {
		if (!A[m - 1][j])
			dp[m - 1][j] = 1;

		else
			break;
	}
	for (int i = m - 1; i >= 0; i--) {
		if (!A[i][n - 1])
			dp[i][n - 1] = 1;

		else
			break;
	}

	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			if (!A[i][j]) {
				dp[i][j] += dp[i][j + 1] ? dp[i][j + 1] : 0;

				dp[i][j] += dp[i + 1][j] ? dp[i + 1][j] : 0;
			}
		}
	}

	return dp[0][0];
}

//or

int uniquePathsWithObstacles(vector<vector<int> > &A) {


	int m = A.size(), n = A[0].size();

	vector<vector<long long> > dp(2, vector<long long> (n, 0));

	for (int j = n - 1; j >= 0; j--) {
		if (!A[m - 1][j])
			dp[1][j] = 1;
		else
			break;
	}

	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {

			if (j == n - 1) {
				if (!A[i][j])
					dp[0][j] = dp[1][j];

				else
					dp[0][j] = 0;

				continue;
			}


			if (!A[i][j]) {
				dp[0][j] = dp[0][j + 1] ? dp[0][j + 1] : 0;

				dp[0][j] += dp[1][j] ? dp[1][j] : 0;
			}

			else
				dp[0][j] = 0;
		}

		dp[1] = dp[0];
	}

	return dp[1][0];
}
