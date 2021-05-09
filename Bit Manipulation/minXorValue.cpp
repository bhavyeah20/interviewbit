int Solution::findMinXor(vector<int> &A) {
	sort(A.begin(), A.end());

	int curr = 0, minn = INT_MAX;

	for (int i = 0; i < A.size() - 1; i++) {
		curr = A[i] ^ A[i + 1];
		minn = min(curr, minn);
	}

	return minn;


}
