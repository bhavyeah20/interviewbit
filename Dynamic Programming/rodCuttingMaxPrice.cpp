int helper(int price[], int len, int n) {
	if (n == 0)
		return 0;

	if (len == 0)
		return 0;

	if (n <= len) {
		return max((price[n - 1] + helper(price, len - n, n)), helper(price, len, n - 1));
	}
	else
		return helper(price, len, n - 1);
}


int cutRod(int price[], int n)
{
	return helper(price, n, n);

}


int cutRod(int price[], int n)
{

	int dp[n + 1][n + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;


	for (int j = 0; j < n + 1; j++)
		dp[0][j] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i <= j)
				dp[i][j] = max((price[i - 1] + dp[i][j - i]), dp[i - 1][j]);

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][n];
}