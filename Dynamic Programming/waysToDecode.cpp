//O(n) + map

unordered_map<string, int> mp;
int mod = 1e9 + 7;
int ways(string s) {

	if (s.size() == 0 || s.size() == 1 && s[0] != '0') {
		return 1;
	}

	if (mp.find(s) != mp.end())
		return mp[s];

	int total = 0;
	if (s[0] != '0') {
		total += ways(s.substr(1)) % mod;
	}

	if (s.substr(0, 2) <= "26" && s[0] != '0') {
		total += ways(s.substr(2)) % mod;
	}

	return mp[s] = total;
}

int Solution::numDecodings(string A) {
	mp.clear();
	return ways(A);
}

// or

//O(n) + array

int mod = 1e9 + 7;
int ways(string s, int i , vector<int> &dp) {

	if (i == s.size()) {
		return 1;
	}

	if (dp[i] != -1)
		return dp[i];

	int total = 0;
	if (s[i] != '0') {
		total += ways(s, i + 1, dp) % mod;
	}

	if (i + 2 <= s.size() && s[i] == '1' || s[i] == '2' && s[i + 1]  <= '6') {
		total += ways(s, i + 2, dp) % mod;
	}

	return dp[i] = total;
}

int Solution::numDecodings(string A) {
	vector<int> dp(A.size() + 1, -1);
	return ways(A, 0, dp);
}


// or

//O(n) + Tabular array

int mod = 1e9 + 7;

int Solution::numDecodings(string s) {
	int n = s.size();
	vector<int> dp(n + 1, 0);
	dp[n] = 1;


	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			dp[i] = 0;
			continue;
		}

		dp[i] = dp[i + 1];

		if ((i + 2 <= n) && ((s[i] == '1') || (s[i] == '2' && s[i + 1]  <= '6')))
			dp[i] += dp[i + 2];

	}
	return dp[0];
}

//O(n) + constant space

int mod = 1e9 + 7;

int Solution::numDecodings(string s) {
	int n = s.size();
	int near = 1, far = 0;
	int curr = 0;
	for (int i = n - 1; i >= 0; i--) {
		curr = near;

		if (s[i] == '0') {
			curr = 0;
		}

		if ((i + 2 <= n) && ((s[i] == '1') || (s[i] == '2' && s[i + 1]  <= '6')))
			curr = (curr % mod +  far % mod ) % mod;

		far = near;
		near = curr;
	}
	return curr;
}

