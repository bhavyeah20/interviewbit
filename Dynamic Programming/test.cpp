#include<bits/stdc++.h>

using namespace std;

int dp[151][151][2];
int mod = 1003;

int ways(string s, int i, int j, bool T) {

	if (i == j) {
		if (T)
			return s[i] == 'T' ? 1 : 0;
		return s[i] == 'T' ? 0 : 1;
	}

	int ans = 0;

	if (dp[i][j][T] != -1)
		return dp[i][j][T];

	for (int k = i + 1; k < j; k += 2) {
		if (dp[i][k - 1][1] == -1)
			dp[i][k - 1][1] = ways(s, i, k - 1, 1);

		if (dp[i][k - 1][0] == -1)
			dp[i][k - 1][0] = ways(s, k + 1, j, 0);


		if (dp[k + 1][j][1] == -1)
			dp[k + 1][j][1] = ways(s, k + 1, j, 1);


		if (dp[k + 1][j][0] == -1)
			dp[k + 1][j][0] = ways(s, k + 1, j, 0);


		if (s[k] == '&') {
			if (T)
				ans += dp[i][k - 1][1] * dp[k + 1][j][1];
			else
				ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][0] * dp[k + 1][j][0];
		}
		else if (s[k] == '|') {
			if (T)
				ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][1];
			else
				ans += dp[i][k - 1][0] * dp[k + 1][j][0];
		}

		else {
			if (T)
				ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1];
			else
				ans += dp[i][k - 1][0] * dp[k + 1][j][0] + + dp[i][k - 1][1] * dp[k + 1][j][1];
		}

	}
	return dp[i][j][T] = ans % mod ;
}

int countWays(int N, string s) {
	memset(dp, -1, sizeof(dp));
	return ways(s, 0, N - 1, true);
}
int main()
{
	string s = "T^F";
	cout << countWays(s.size(), s);
}
