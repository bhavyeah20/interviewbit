int Solution::searchInsert(vector<int> &A, int B) {

	// return lower_bound(A.begin(), A.end(), B) - A.begin();



	int n = A.size();
	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == B)
			res = mid, end = mid - 1;

		if (A[mid] < B) {
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return ((res == -1) ? start : res);

}


