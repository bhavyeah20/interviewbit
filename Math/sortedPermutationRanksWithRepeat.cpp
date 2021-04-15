#define MOD 1000003
#define ll long long

ll factorial(ll n)
{
	if (n == 0 || n == 1)
		return 1;

	ll dp[n + 1];
	dp[0] = dp[1] = 1;

	for (ll i = 2; i <= n; i++)
		dp[i] = ((i % MOD) * (dp[i - 1] % MOD)) % MOD;

	return dp[n];
}

ll powerr(ll a, ll b)
{

	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = ((res % MOD) * (a % MOD)) % MOD;

		a = ((a % MOD) * (a % MOD)) % MOD;
		b >>= 1;
	}
	return res;
}


int Solution::findRank(string A) {

	vector<int> presentCount(256, 0);
	unordered_map<int, int>  mp;
	int n = A.size();

	for (int i = 0; i < n; i++)
	{
		presentCount[A[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		mp[A[i]] = presentCount[A[i]];
	}



	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (j == A[i])
				break;

			if (presentCount[j])
			{

				// cout << "For char " << j << "present count was " << presentCount[j] << endl;
				presentCount[j]--;

				ll denom = 1;
				for (auto it : mp)
				{
					if (it.first == j)
						continue;

					denom = ((denom % MOD) * (powerr(factorial(it.second), MOD - 2) % MOD)) % MOD;

				}
				denom = ((denom % MOD) * (powerr(factorial(presentCount[j]), MOD - 2) % MOD)) % MOD;


				ans = ans % MOD + ((factorial(n - i - 1) % MOD) * (denom % MOD)) % MOD;
				// cout << endl;
				// cout << ans << " ";
				presentCount[j]++;
			}

		}

		presentCount[A[i]]--;
		mp[A[i]]--;

	}


	return (ans + 1) % MOD;
}