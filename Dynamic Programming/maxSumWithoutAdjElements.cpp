int sum(int j, vector<vector<int> > &A, vector<int> &dp) {
	if (j == A[0].size() || j == A[0].size() + 1)
		return 0;

	if (dp[j] != -1)
		return dp[j];

	int sum1 = sum(j + 2, A, dp);

	int curr = max(A[0][j], A[1][j]) + sum1;


	return dp[j] = max(curr, sum(j + 1, A, dp));

}

int Solution::adjacent(vector<vector<int> > &A) {
	vector<int> dp(A[0].size(), -1);
	return sum(0, A, dp);

}

//or

int Solution::adjacent(vector<vector<int> > &A) {
	int n = A[0].size();
	vector<int> dp(n + 2, 0);

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = max(max(A[0][i], A[1][i]) + dp[i + 2], dp[i + 1]);
	}

	return dp[0];

}


//or

int Solution::adjacent(vector<vector<int> > &A)
{
	int n = A[0].size(); //size of arr

	for (int i = 0; i < n; i++) //store max for each coloum
		A[0][i] = max(A[0][i], A[1][i]);

	A[0][1] = max(A[0][0], A[0][1]); //for 2nd element choose max among first end second

	for (int i = 2; i < n; i++)
		A[0][i] = max(A[0][i - 1], A[0][i - 2] + A[0][i]);

	return max(A[0][n - 1], A[0][n - 2]);
}
