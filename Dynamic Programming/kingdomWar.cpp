int Solution::solve(vector<vector<int> > &A) {
	int R = A.size(), C = A[0].size();
	vector<int> sum(R, 0);
	int maxArea = INT_MIN;

	for (int left = C - 1; left >= 0; left--) {

		for (int row = 0; row < R; row++) {
			sum[row] += A[row][left];
		}

		int curr = 0;
		for (int row = 0; row < R; row++) {
			curr += sum[row];
			maxArea = max(maxArea , curr);

			if (curr < 0)
				curr = 0;
		}
	}

	return maxArea;
}
