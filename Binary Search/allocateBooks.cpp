int Solution::books(vector<int> &A, int B) {
	int n = A.size();
	if (B > n)
		return -1;
	int start = *max_element(A.begin(), A.end());
	int end = 0;
	for (int x : A)
		end += x;

	int minPages = INT_MAX;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		int curr = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			curr += A[i];
			if (curr > mid) {
				cnt++, curr = 0;
				i--;
			}
		}

		cnt++;

		if (cnt == B)
			minPages = mid, end = mid - 1;

		else if (cnt > B) {
			start = mid + 1;
		}

		else
			minPages = min(minPages, mid), end = mid - 1;
	}

	return minPages;
}
