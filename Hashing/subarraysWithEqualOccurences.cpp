int Solution::solve(vector<int> &A, int B, int C) {
	int n = A.size();
	unordered_map<int, int> mp; //diff -> cnt
	mp[0] = 1;
	int cnt = 0;
	int diff = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == B)
			diff++;

		if (A[i] == C)
			diff--;

		if (mp.find(diff) != mp.end()) {
			cnt += mp[diff];
		}

		mp[diff]++;
	}

	return cnt;
}

//or


int Solution::solve(vector<int> &A, int B, int C) {
	int n = A.size();
	vector<int> pB(n, 0), pC(n, 0);

	pB[0] = A[0] == B ? 1 : 0;
	pC[0] = A[0] == C ? 1 : 0;

	for (int i = 1; i < n; i++) {
		pB[i] = pB[i - 1] + (A[i] == B ? 1 : 0);
		pC[i] = pC[i - 1] + (A[i] == C ? 1 : 0);
	}

	unordered_map<int, int> mp; //diff -> cnt
	mp[0] = 1;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int diff = pB[i] - pC[i];
		if (mp.find(diff) != mp.end()) {
			cnt += mp[diff];
		}

		mp[diff]++;
	}

	return cnt;
}
