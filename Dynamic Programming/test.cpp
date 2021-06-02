#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int dp[1001][1001];


int subsetSumMemoized(vector<int> wt, int target, int n, int **dp) {

	if (target == 0)
		return 1;

	if (n == 0)
		return 0;

	if (dp[n][target] == -1) {

		if (wt[n - 1] <= target) {
			dp[n][target] =
			    subsetSumMemoized(wt, target, n - 1, dp) || subsetSumMemoized(wt, target - wt[n - 1], n - 1, dp);
		}

		else
			dp[n][target] =  subsetSumMemoized(wt, target, n - 1, dp);

	}

	return dp[n][target];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 3;
	int t = 7;
	int **dp = new int *[n + 1];
	for (int i = 0; i < n + 1; i++)
		dp[i] = new int [t + 1];


	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < t + 1; j++)
			dp[i][j]  = -1;
	}

	vector<int> wt({1, 2, 4});
	cout << subsetSumMemoized(wt, 7, 3, dp) << endl;

	for (int i = 0; i < wt.size() + 1; i++) {
		for (int j = 0; j < 8; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}


}