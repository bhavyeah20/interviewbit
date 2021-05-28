int Solution::solve(vector<int> &A) {

	unordered_map<int, int> mp;
	int len = 0, sum = 0;
	mp[0] = -1;
	for (int i = 0; i < A.size(); i++) {

		sum += A[i] ? 1 : -1;

		if (mp.find(sum - 1) != mp.end()) {
			len = max(len, i - mp[sum - 1]);
		}

		if (mp.find(sum) == mp.end())
			mp[sum] = i;
	}

	return len;
}