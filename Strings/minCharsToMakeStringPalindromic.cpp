int Solution::solve(string A) {
	int cnt = 0;
	while (1) {
		int n = A.size() + cnt;
		int mid = (n - 1) / 2;

		int i = mid - cnt, j = mid + 1 - cnt;

		if (n & 1)
			i--;

		while (i >= 0 && j < n && A[i] == A[j])
			i--, j++;

		if (i == -1)
			return A.size() - j;

		cnt++;

	}
}

// or

// vector<int> prefixFunction(string &s) {
// 	vector<int> pi(s.size(), 0);
// 	pi[0] = 0;
// 	int n = s.size();
// 	int len = 0; //pi(i)
// 	for (int i = 1; i < n; i++) {
// 		if (s[len] == s[i]) {
// 			len++;
// 			pi[i] = len;
// 			continue;
// 		}

// 		while (len > 0 && s[len] != s[i]) {
// 			len = pi[len - 1];
// 		}

// 		if (s[len] == s[i])
// 			len++;

// 		pi[i] = len;
// 	}

// 	return pi;
// }

// int Solution::solve(string A) {
// 	string B = A;
// 	reverse(A.begin(), A.end());
// 	A = B + "$" + A;
// 	vector<int> pre = prefixFunction(A);

// 	return B.size() - pre[A.size() - 1];
// }
