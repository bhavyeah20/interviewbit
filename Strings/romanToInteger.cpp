int Solution::romanToInt(string A) {
	unordered_map<char, int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;

	int ans = 0;

	for (int i = 0; i < A.size(); i++) {
		if (i < A.size() - 1 && mp[A[i + 1]] > mp[A[i]]) {
			ans -= mp[A[i]];
		} else {
			ans += mp[A[i]];
		}
	}

	return ans;



}
