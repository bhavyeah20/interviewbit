#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> cuts;
vector<int> ans;
vector<vector<ll>> dp;
vector<vector<ll>> pr;

void make(int l, int r);
ll f(int l, int r);
vector<int> Solution::rodCut(int A, vector<int> &B) {
	B.push_back(A);
	B.insert(B.begin(), 0);
	ll n = B.size();
	cuts.clear();
	ans.clear();
	dp = vector<vector<ll>> (n, vector<ll> (n, -1));
	pr = vector<vector<ll>> (n, vector<ll> (n, -1));

	for (int i = 0; i < n; ++i)
		cuts.push_back(B[i]);

	f(0, n - 1);

	make(0, n - 1);

	return ans;
}

void make(int l, int r) {
	if (l + 1 >= r) return;

	ans.push_back(cuts[pr[l][r]]);

	make(l, pr[l][r]);
	make(pr[l][r], r);
}

ll f(int l, int r) {
	if (l + 1 >= r) return 0;

	if (dp[l][r] != -1) return dp[l][r];

	ll res = LONG_LONG_MAX, bin = -1;


	for (int k = l + 1; k < r; ++k) {
		ll c = cuts[r] - cuts[l] + f(l, k) + f(k, r);

		if (c < res) {
			res = c;
			bin = k;
		}
	}

	dp[l][r] = res;
	pr[l][r] = bin;

	return res;
}
int main()
{
	vector<int> v({1, 2, 5});
	vector<int> ans =  rodCut(6, v);
	for (int x : ans)
		cout << x << " ";
}
