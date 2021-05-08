int Solution::solve(string A) {
	int n = A.size();
	int cnt = 0;

	while (1) {
		int newN = n + cnt;
		int mid = (newN - 1) / 2;
		int i = mid, j = mid;
		if (!(newN & 1)) {
			j++;
		}

		while (j < n && A[i] == A[j]) {
			i--, j++;
		}

		if (j == n)
			return cnt;
		cnt++;
	}
}

// or

// N - LPS Of reversed array


int lps(string s) {
	int n = s.size();
	int i = 0, j = 0;
	int pi[n] = {0};

	for (int i = 1; i < n; i++) {
		j = pi[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		if (s[i] == s[j])
			j++;

		pi[i] = j;
	}

	return pi[n - 1];

}

int Solution::solve(string A) {
	int n = A.size();
	string B = A;
	reverse(A.begin(), A.end());
	B = A + '$' + B;

	return n - lps(B);
}