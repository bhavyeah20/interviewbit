
#define ll long long int

ll powerr(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = ((res % mod) * (a % mod)) % mod;

		a = ((a % mod) * (a % mod)) % mod;
		b >>= 1;
	}

	return res % mod;
}

ll prefixFunction(string s) {
	ll n = s.size();
	ll pre[n] = {0};
	for (ll i = 1; i < n; i++) {
		ll j = pre[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pre[j - 1];

		if (s[i] == s[j])
			j++;

		pre[i] = j;
	}

	return pre[n - 1];
}

int solve(vector<string> &A) {
	ll n = A.size();
	ll mod = 1e9 + 7;
	vector<ll> t;
	for (ll i = 0; i < n; i++) {
		ll M = A[i].size();
		ll lps = prefixFunction(A[i]);
		ll len = 0;
		if (!(M % (M - lps)))
			len = M - lps;
		else
			len = M;

		for (ll j = 1; j <= 2 * len - 1; j++) {
			if (((j * (j + 1)) / 2) % len == 0) {
				len = j;
				break;
			}
		}

		t.push_back(len);
	}

	ll curr = 1;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			t[j] /= __gcd(t[i], t[j]);
		}

		curr = ((t[i] % mod * curr % mod) % mod);

	}


	return curr % mod;


}

// 1. Search for recurring pattern
// 2. Take lcm of all ti
// 3. Pay special attention to how mod is used with lcm
// 4. As we are using gcd hence we cant take gcd(curr,ti) as curr as already been modded hence factors would change
