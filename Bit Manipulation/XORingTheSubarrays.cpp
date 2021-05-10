int Solution::solve(vector<int> &A) {
	int ans = 0;
	int N = A.size();
	for (int i = 0; i < N; i++) {
		int t = ((i + 1) * (N - i)) & 1;
		if (t) {
			ans ^= A[i];
		}

	}

	return ans;
}
