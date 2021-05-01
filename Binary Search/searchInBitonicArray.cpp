int Solution::solve(vector<int> &A, int B) {

	int n = A.size();
	int start = 0, end = n - 1;
	int peak = -1;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
			peak = mid;
			break;
		}
		if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
			start = mid + 1;

		else
			end = mid - 1;

	}

	int ans1 = -1, ans2 = -1;

	int s1 = 0, e1 = peak, s2 = peak + 1, e2 = n - 1;


	while (s1 <= e1) {
		int mid = (s1 + e1) / 2;

		if (A[mid] == B)
			return mid;

		if (A[mid] < B)
			s1 = mid + 1;

		else
			e1 = mid - 1;

	}


	while (s2 <= e2) {
		int mid = (s2 + e2) / 2;

		if (A[mid] == B)
			return mid;

		if (A[mid] < B)
			s2 = mid + 1;

		else
			e2 = mid - 1;

	}

	return -1;
}
