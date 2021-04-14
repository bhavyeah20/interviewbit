#include<bits/stdc++.h>
using namespace std;

#define MOD 1000003


long long int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;

	long long int  dp[n + 1];
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = ((i % MOD) * (dp[i - 1] % MOD)) % MOD;

	return dp[n];
}

long long modPow (long long a, long long n) {

	long long ans = 1;

	while (n > 0) {

		if (n & 1)
			ans = (ans * a) % MOD;

		a = (a * a) % MOD;
		n >>= 1;
	}

	return ans;
}

int findRank(string A) {

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



	long long int ans = 0;

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

				long long int denom = 1;
				for (auto it : mp)
				{
					if (it.first == j)
						continue;

					denom = (denom * factorial(it.second)) % MOD;
				}

				denom = (denom * factorial(presentCount[j])) % MOD;

				// cout << denom << " ";
				// denom = modPow(denom, MOD - 2);
				ans += ((factorial(n - i - 1) % MOD) * (denom % MOD)) % MOD;
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

int main()
{
	string s = "cdaabcd";
	cout << findRank(s);
}