int calc(string A, int i, int j) {
	int w = 0, b = 0;

	for (int idx = i; idx <= j; idx++) {
		if (A[idx] == 'B')
			b++;
		else
			w++;
	}

	return b * w;
}

int cost(string A, int i, int j, int cuts, vector<vector<int> > &dp) {
	if (cuts == 0)
		return dp[cuts][i] = calc(A, i, j);

	if (dp[cuts][i] != -1)
		return dp[cuts][i];

	int ans = 10000000;
	for (int k = i; k < j; k++) {
		int curr = calc(A, i, k) + cost(A, k + 1, j, cuts - 1, dp);

		ans = min(curr, ans);
	}

	return dp[cuts][i] = ans;
}

int Solution::arrange(string A, int B) {
	if (!B)
		return -1;

	if (A.size() < B)
		return -1;
	vector<vector<int> > dp(B, vector<int> (A.size(), -1));
	return cost(A, 0, A.size() - 1, B - 1, dp);
}

//or
//observe filling pattern
// <--------   dp[0][i]
// <-------
// <------
//.
//.
//.
//<            dp[B-1][i]
int calc(string A, int i, int j) {
	int w = 0, b = 0;

	for (int idx = i; idx <= j; idx++) {
		if (A[idx] == 'B')
			b++;
		else
			w++;
	}

	return b * w;
}


int Solution::arrange(string A, int B) {
	int n = A.size();
	int j = n - 1;
	if (!B)
		return -1;

	if (A.size() < B)
		return -1;

	vector<vector<int> > dp(B, vector<int> (A.size(), 10000000));

	for (int i = 0; i < n; i++)
		dp[0][i] = calc(A, i, j);


	for (int cuts = 1; cuts < B; cuts++) {
		for (int i = j - cuts; i >= 0 ; i--) {
			for (int k = i; k <= j - cuts; k++) {
				dp[cuts][i] = min(calc(A, i, k) + dp[cuts - 1][k + 1], dp[cuts][i]);
			}
		}
	}

	return dp[B - 1][0] = ans;
}
