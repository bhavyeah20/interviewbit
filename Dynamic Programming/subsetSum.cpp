#include<bits/stdc++.h>

using namespace std;

int dp[10001][10001];

int subsetSum(vector<int> wt, int target, int n) {

	if (target == 0)
		return 1;

	if (n == 0)
		return 0;

	if (wt[n - 1] <= target) {
		return subsetSum(wt, target - wt[n - 1], n - 1) ||
		       subsetSum(wt, target, n - 1);
	}

	else
		return subsetSum(wt, target, n - 1);


}

int subsetSumMemoized(vector<int> wt, int target, int n) {

	if (target == 0)
		return 1;

	if (n == 0)
		return 0;

	if (dp[n][target] == -1) {

		if (wt[n - 1] <= target) {
			dp[n][target] =  subsetSumMemoized(wt, target - wt[n - 1], n - 1) ||
			                 subsetSumMemoized(wt, target, n - 1);
		}

		else
			dp[n][target] =  subsetSumMemoized(wt, target, n - 1);

	}

	return dp[n][target];
}

int subsetSumTabular(vector<int> wt, int target, int n) {

	for (int j = 0; j < target + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < target + 1; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = (dp[i - 1][j - wt[i - 1]]) || (dp[i - 1][j]);
			}

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][target];
}

int subsetSumSpaceOptimized() {
	int n = nums.length;
	boolean[] dp = new boolean[sum + 1];
	Arrays.fill(dp, false);
	dp[0] = true;

	for (int num : nums) {
		for (int i = sum; i > 0; i--) {
			if (i >= num) {
				dp[i] = dp[i] || dp[i - num];
			}
		}
	}
}
int main() {

	memset(dp, -1, sizeof(dp));
	vector<int> wt({479 , 758 , 315 , 472 , 730 , 101 , 460 , 619});
	cout << subsetSum(wt, 1967, 8);
	cout << subsetSumMemoized(wt, 1967, 8);
	cout << subsetSumTabular(wt, 1967, 8);
}