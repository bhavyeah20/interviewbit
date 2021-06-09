int dp[100001];
int mod = 1e9 + 7;

int dominos(int A) {
	if (A == 0)
		return 1;

	if (A == 1)
		return 1;

	if (dp[A] != -1)
		return dp[A];


	if (A & 1) {
		return dp[A] = (dominos(A - 1) % mod + dominos(A - 2) % mod) % mod;
	}

	return dp[A] = (dominos(A - 2) % mod + 2 * dominos(A - 1) % mod) % mod;

}

int Solution::solve(int A) {
	if (A & 1)
		return 0;

	memset(dp, -1, sizeof(dp));

	return dominos(A);
}


//

int Solution::solve(int A) {
	if (A & 1)
		return 0;

	int dp[A + 1];
	int mod = 1e9 + 7;

	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i < A + 1; i++) {
		if (i & 1) {
			dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
		} else {
			dp[i] = (dp[i - 2] % mod + 2 * dp[i - 1] % mod) % mod;
		}
	}

	return dp[A];
}

