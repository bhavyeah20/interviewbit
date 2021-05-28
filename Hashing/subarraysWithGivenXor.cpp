int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	unordered_map<int, int> xorMap;
	vector<int> prefixXor(n);
	xorMap[0] = 1;
	prefixXor[0] = A[0];
	for (int i = 1; i < n; i++) {
		prefixXor[i] = prefixXor[i - 1] ^ A[i];
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {

		int xr = prefixXor[i] ^ B;

		if (xorMap.find(xr) != xorMap.end())
			cnt += xorMap[xr];

		xorMap[prefixXor[i]]++;
	}

	return cnt;
}

