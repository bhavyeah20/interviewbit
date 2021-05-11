int Solution::cntBits(vector<int> &A) {
	long long mod = 1e9 + 7;
	long long n = A.size();
	long long curr = 0;
	long long maxx = *max_element(A.begin(), A.end());
	long long digits = log2(maxx) + 1;
	for (long long j = 0; j < digits; j++) {
		long long cnt = 0;
		for (long long i = 0; i < n ; i++) {
			cnt = (cnt % mod +  ((A[i] >> j) & 1) % mod) % mod;
		}

		curr = ((curr % mod) + ((2 % mod) * (cnt % mod ) * ((n - cnt) % mod)) % mod) % mod;

	}




	return (curr % mod);
}
