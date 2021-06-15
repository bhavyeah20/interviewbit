void partition(string A, int start, string curr, vector<string> &ans, unordered_map<string, int> &mp, vector<bool> &dp) {
	if (start == A.size()) {
		curr.pop_back();

		ans.push_back(curr);
		return ;
	}

	for (int i = start; i < A.size(); i++) {
		string key = A.substr(start, i - start + 1);
		if (mp.find(key) != mp.end() && dp[i + 1]) {
			curr += key;
			curr.push_back(' ');
			partition(A, i + 1, curr, ans, mp, dp);

			for (int t = 0; t <= key.length(); t++)
				curr.pop_back();
		}
	}
}


vector<string> Solution::wordBreak(string A, vector<string> &B) {
	int n = A.size();
	unordered_map<string, int> mp;
	for (string b : B)
		mp[b]++;

	vector<bool> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int k = i; k < n; k++) {
			string key = A.substr(i, k - i + 1);
			if (mp.find(key) != mp.end())
				dp[i] = dp[i + key.length()];

			if (dp[i])
				break;
		}
	}

	vector<string> ans;
	partition(A, 0, "", ans, mp, dp);
	sort(ans.begin(), ans.end());
	return ans;
}
