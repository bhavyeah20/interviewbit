#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int knapSack(vector<int> wt, vector<int> val, int W, int n) {

	if (W == 0 || n == 0)
		return 0;

	if (wt[n - 1] <= W) {
		return max(val[n - 1] + knapSack(wt, val, W - wt[n - 1], n - 1),
		           knapSack(wt, val, W, n - 1));
	}
	else
		return knapSack(wt, val, W, n - 1);
}

int knapSackMemoized(vector<int> wt, vector<int> val, int W, int n) {

	if (W == 0 || n == 0)
		return 0;

	if (dp[n][W] == -1) {
		if (wt[n - 1] <= W) {
			dp[n][W] =  max(val[n - 1] + knapSackMemoized(wt, val, W - wt[n - 1], n - 1),
			                knapSack(wt, val, W, n - 1));
		}
		else
			dp[n][W] =  knapSackMemoized(wt, val, W, n - 1);
	}
	return dp[n][W];
}

int knapSackTabular(vector<int> wt, vector<int> val, int W, int n) {

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < W + 1; j++)
		dp[0][j] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {

			if (wt[i - 1] <= j) {
				dp[i][j] =  max(val[i - 1] + dp[i - 1][j - wt[i - 1]],
				                dp[i - 1][j]);
			}
			else
				dp[i][j] =  dp[i - 1][j];
		}
	}

	return dp[n][W];

}

int main() {
	memset(dp, -1, sizeof(dp));

	vector<int> wt({ 2, 3, 4, 5});
	vector<int> val({4, 5, 3, 2});

	cout << knapSackTabular(wt, val, 7, 4);
}