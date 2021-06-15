//Recursion
unordered_map<string, int> mp;

bool partition(string A, int i, int j) {
	if (i == A.size())
		return true;

	for (int k = i; k < A.size(); k++) {
		if (mp.find(A.substr(i, k - i + 1)) != mp.end() && partition(A, k + 1, j)) {
			return true;
		}
	}

	return false;

}

int Solution::wordBreak(string A, vector<string> &B) {
	mp.clear();

	for (string b : B)
		mp[b]++;

	return partition(A, 0, A.size() - 1);
}

//Memoized
//dp(i) -> can A.substr(i) be broken into words ? i.e A.substr(i,k-i+1) is present in wordDict and A[k+1...j] can also be broken
//dp(0) -> ans
unordered_map<string, int> mp;

bool partition(string A, int i, int j, vector<int> &dp) {
	if (i == A.size())
		return true;

	if (dp[i] != -1)
		return dp[i];

	for (int k = i; k < A.size(); k++) {
		if (mp.find(A.substr(i, k - i + 1)) != mp.end() && partition(A, k + 1, j, dp)) {
			return dp[i] = true;
		}
	}

	return dp[i] = false;

}

bool wordBreak(string A, vector<string> &B) {
	mp.clear();

	for (string b : B)
		mp[b]++;

	vector<int> dp(A.size(), -1);
	return partition(A, 0, A.size() - 1, dp);
}

// Tabular

bool wordBreak(string A, vector<string> &B) {
	unordered_map<string, int> mp;
	int n = A.size();
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

	return dp[0];

}
