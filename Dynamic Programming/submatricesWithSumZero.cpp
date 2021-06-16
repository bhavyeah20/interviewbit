int numSubmatrixSumTarget(vector<vector<int>>& A, int T) {
	int n = A.size(), m = A[0].size();
	vector<int> prefix(n, 0);
	int cnt = 0;
	for (int L = 0; L < m; L++) {
		fill_n(prefix.begin(), n, 0);
		for (int R = L; R < m; R++) {

			for (int i = 0; i < n; i++) {
				prefix[i] += A[i][R];
			}

			unordered_map<int, int> mp;
			mp[0] = 1;
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += prefix[i];
				int target = sum - T;
				if (mp.find(target) != mp.end()) {
					cnt += mp[target];
				}
				mp[sum]++;
			}
		}
	}

	return cnt;
}
