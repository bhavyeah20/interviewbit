int Solution::lengthOfLongestSubstring(string A) {
	unordered_map<char, int> mp;
	int len = 0;
	int i = 0, j = 0;
	for (int j = 0; j < A.size(); j++) {
		if (mp.find(A[j]) != mp.end()) {

			i = max(i, mp[A[j]] + 1);
			//abba

		}

		mp[A[j]] = j;
		len = max(len, j - i + 1);
	}

	return len;
}

//or

int Solution::lengthOfLongestSubstring(string A) {
	queue<char> q;
	unordered_map<char, bool> mp;
	int len = 0;
	for (char x : A) {
		if (mp.find(x) != mp.end()) {
			while (!q.empty() && q.front() != x) {
				mp.erase(q.front());
				q.pop();
			}

			mp.erase(x);
			q.pop();

		}

		q.push(x), mp[x] = 1;
		len = max(len, (int)q.size());
	}

	return len;
}
