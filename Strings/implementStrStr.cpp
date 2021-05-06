vector<int> prefixFunction(string s) {
	int n = s.size();
	int i = 0, j = 0;
	vector<int> pi(n, 0);

	for (int i = 1; i < n; i++) {
		j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		if (s[i] == s[j])
			j++;

		pi[i] = j;
	}

	return pi;
}

int Solution::strStr(const string A, const string pat) {

	if (!pat.size() || !A.size())
		return -1;
	vector<int> pi = prefixFunction(pat);
	int j = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == pat[j]) {
			j++;
			if (j == pat.size()) {
				return i - j + 1;
			}
			continue;
		}
		if (j) {
			i--;
			j = pi[j - 1];
		}
	}

	return -1;

}
