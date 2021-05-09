int Solution::solve(int A) {
	int mod = 1e9 + 7;
	int cnt = log2(A) + 1;
	int ans = 0;

	for (int i = 1; i <= cnt; i++) {
		int rep = pow(2, i);
		ans = (ans % mod) +  (((A + 1) / rep) * (rep / 2)) % mod;
		if ((((A + 1) % rep) - rep / 2) > 0)
			ans = (ans % mod) +  ((A + 1) % rep - rep / 2) % mod;
	}

	return ans % mod;

}
