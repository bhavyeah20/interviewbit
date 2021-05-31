class Solution {

public:

	int minDiffMemo(int arr[], int s1, int s2, int n, int **dp) {
		if (n == 0)
			return abs(2 * s1 - s2);

		if (dp[s1][n] == -1) {
			dp[s1][n] =  min(minDiffMemo(arr, s1 + arr[n - 1], s2, n - 1, dp), minDiffMemo(arr, s1, s2, n - 1, dp));
		}
		return dp[s1][n];
	}

	int minDiffernce(int arr[], int n)
	{
		t = 0;
		for (int i = 0; i < n; i++)
			t += arr[i];

		int **dp;
		dp = new int* [t + 1];
		for (int i = 0; i < t + 1; i++)
			dp[i] = new int [n + 1];

		for (int i = 0; i < t + 1; i++) {
			for (int j = 0; j < n + 1; j++)
				dp[i][j] = -1;
		}

		return minDiffMemo(arr, 0, t, n, dp);
	}
};

//or

class Solution {

public:

	int minDiffernce(int arr[], int n) {
		int t = 0;
		for (int i = 0; i < n; i++)
			t += arr[i];

		bool dp[n + 1][t + 1];


		for (int j = 0; j < t + 1; j++)
			dp[0][j] = 0;

		for (int i = 0; i < n + 1; i++)
			dp[i][0] = 1;

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < t + 1; j++) {
				if (arr[i - 1] <= j)
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];

				else
					dp[i][j] = dp[i - 1][j];
			}
		}


		int minn = INT_MAX;
		for (int j = 0; j <= t / 2; j++) {
			minn = min(minn, t - 2 * ((dp[n][j]) ? j : 0));
		}

		return minn;

	}
};