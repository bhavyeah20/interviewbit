string Solution::convert(string A, int B) {
	int n = A.size();
	vector<string > ans(B);

	if (B == 0)
		return "";
	if (B == 1)
		return A;

	int j = 0, counter = 1;
	for (int i = 0; i < n; i++) {
		ans[j].push_back(A[i]);
		j += counter;

		if (j == B)
			j = B - 2, counter = -1;

		if (j == -1)
			j = 1, counter = 1;
	}

	string s = "";

	for (auto emt : ans) {
		s += emt;
	}

	return s;
}