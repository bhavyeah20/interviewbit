string LCS(string x, string y) {
	int n = x.size(), m = y.size();
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], d[i][j - 1]);
		}
	}


	int i = n, j = m;
	string ans = "";
	while (i > 0 && j > 0) {
		if (x[i - 1] == y[j - 1]) {
			ans.push_back(x[i - 1]);
			i--, j--;
		}

		else {
			if (dp[i - 1][j] < dp[i][j - 1])
				j--;

			else
				i--;
		}
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

// BT

void LCS(int start, int pI, string x, string y, string curr, string &ans) {
	if (start == x.size()) {
		if (ans.length() < curr.length())
			ans = curr;
		return ;
	}


	for (int i = start; i < x.size(); i++) {
		for (int j = pI; j < y.size(); j++) {
			if (x[i] == y[j]) {
				curr.push_back(x[i]);
				LCS(i + 1, j + 1, x, y, curr, ans);

				curr.pop_back();
			}
		}
	}
}
