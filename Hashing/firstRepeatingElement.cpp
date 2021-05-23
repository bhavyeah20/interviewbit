int Solution::solve(vector<int> &A) {
	unordered_map<int, int> mpValue;
	int minI = INT_MAX;
	for (int i = A.size() - 1; i >=  0; i--) {

		mpValue[A[i]]++;

		if (mpValue[A[i]] > 1) {
			minI = min(minI, i);
		}

	}

	return minI == INT_MAX ? -1 : A[minI];

}

