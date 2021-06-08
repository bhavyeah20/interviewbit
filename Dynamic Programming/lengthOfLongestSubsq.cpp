int Solution::longestSubsequenceLength(const vector<int> &A) {

	int n = A.size();
	if (n == 1)
		return 1;
	vector<int> dp1(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}

	}

	vector<int> dp2(n, 1);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (A[j] < A[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}

	}

	int maxLen = INT_MIN;

	for (int i = 0; i < n; i++) {
		maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
	}

	return maxLen == INT_MIN ? n : maxLen;





}
