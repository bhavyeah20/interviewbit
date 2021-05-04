int Solution::solve(string A) {
	int cnt = 0;
	while (1) {
		int n = A.size();
		int mid = (n - 1) / 2;

		int i, j;
		if (n & 1) {
			i = mid - 1;
			j = mid + 1;
		} else {
			i = mid;
			j = mid + 1;
		}
		while (i >= 0 && j < n && (A[i] == A[j] || A[i] == '0'))
			i--, j++;

		if (i == -1)
			return cnt;

		A.insert(0, 1, '0');
		cnt++;
	}
}


