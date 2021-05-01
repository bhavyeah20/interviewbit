int Solution::findMin(const vector<int> &A) {
	int n = A.size();
	int start = 0, end = n - 1;
	int mid;
	while (start < end) {
		mid = start + (end - start) / 2;

		if (A[start] < A[end])
			return A[start];

		if (A[start] <= A[mid]) {
			start = mid + 1;
		}

		else
			end = mid;
	}

	return A[start];
}