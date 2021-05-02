int Solution::sqrt(int A) {
	int start = 1;
	int end = A;
	int ans;

	if (A == 0)
		return 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (mid == A / mid)
			return mid;

		if (mid < A / mid)
			ans = mid, start = mid + 1;

		else
			end = mid - 1;

	}

	return ans;


}
