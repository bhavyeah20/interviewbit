long long int prefixFunction(string s) {
	long long int n = s.size();
	long long int pre[n] = {0};
	for (long long int i = 1; i < n; i++) {
		long long int j = pre[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pre[j - 1];

		if (s[i] == s[j])
			j++;

		pre[i] = j;
	}

	return pre[n - 1];
}

long long int fpow(long long int x, long long int y) {
	long long int mod = 1e9 + 7;
	long long int res = 1;
	while (y) {
		if (y & 1) {
			res = ((res % mod) * (x % mod)) % mod;
		}

		x = ((x % mod) * (x % mod)) % mod;
		y >>= 1;
	}

	return res % mod;
}

long long int finalX(long long int x) {
	long long int t = 1;
	while (1) {
		long long int t1 = (t * (t + 1) ) / 2;
		if (t1 % x == 0)
			return t;
		t++;
	}
}

int Solution::solve(vector<string> &A) {
	long long int n = A.size();
	long long int mod = 1e9 + 7;
	vector<long long int> t;
	for (long long int i = 0; i < n; i++) {
		long long int x = 1;
		long long int m = prefixFunction(A[i]);
		long long int len = 0;

		if (!(A[i].size() % (A[i].size() - m)))
			len = A[i].size() - m;
		else
			len = A[i].size();


		x = finalX(len);
		t.push_back(x);
	}

	long long int curr = 1;
	for (long long int x : t) {
		curr = (((x % mod * curr % mod) % mod) * fpow(__gcd(x, curr), mod - 2)) % mod;
	}

	return curr % mod;


}
