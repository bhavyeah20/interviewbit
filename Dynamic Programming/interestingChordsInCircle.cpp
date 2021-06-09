long long int mod = 1e9 + 7;

int Solution::chordCnt(int A) {
	vector<long long int> dp(A + 1, 0);
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= A; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = ((dp[i] % mod) + ((dp[j] % mod) * (dp[i - j - 1] % mod)) % mod) % mod;
		}
	}

	return dp[A];

}
