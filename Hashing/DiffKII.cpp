int Solution::diffPossible(const vector<int> &A, int B) {
	unordered_map<int, int> mp;
	for (int x : A) {
		if (mp[x - B] || mp[x + B]) {
			return 1;
		}
		mp[x] = 1;
	}

	return 0;
}
