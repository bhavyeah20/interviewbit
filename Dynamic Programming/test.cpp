#include<bits/stdc++.h>

using namespace std;

int dp[101][101];

int subset(vector<int>& wt, int t, int n) {


	int count = 0;
	for (int j = 0; j < t + 1; j++) {
		dp[0][j] = 0;
	}
	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < t + 1; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - wt[i - 1]] + dp[i - 1][j];
			}

			else
				dp[i][j] = dp[i - 1][j];

		}
	}

	return dp[n][t];

}


int main() {

	vector<int> wt({2, 3, 5, 6, 8, 10});
	cout << subset(wt, 10, wt.size());
}