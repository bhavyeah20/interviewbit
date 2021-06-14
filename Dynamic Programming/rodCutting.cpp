void getAns(int i, int j, vector<vector<int> > &dp, vector<int> &ans, vector<int> &cuts) {
	if (j - i <= 1)
		return ;

	for (int k = i + 1; k < j; k++) {
		if (dp[i][k] + dp[k][j] + cuts[j] - cuts[i] == dp[i][j]) {
			ans.push_back(cuts[k]);
			getAns(i, k, dp, ans, cuts);
			getAns(k, j, dp, ans, cuts);
			return ;
		}
	}
}

int cost(int i, int j, vector<int> &cuts, vector<vector<int> > &dp) {

	if (i == j || j - i == 1)
		return dp[i][j] = 0;

	int minCost = INT_MAX;
	int currCost = 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	for (int idx = i + 1; idx < j; idx++) {
		currCost = cuts[j] - cuts[i] + cost(i, idx, cuts, dp) + cost(idx, j, cuts, dp);
		minCost = min(minCost, currCost);
	}

	return dp[i][j] = minCost == INT_MAX ? 0 : minCost;
}


vector<int> Solution::rodCut(int n, vector<int> &cuts) {
	cuts.push_back(0), cuts.push_back(n);
	sort(cuts.begin(), cuts.end());
	vector<vector<int> > dp(cuts.size() + 1, vector<int> (cuts.size() + 1, -1));
	int costt =  cost(0, cuts.size() - 1, cuts, dp);

	vector<int> ans;
	getAns(0, cuts.size() - 1, dp, ans, cuts);
	return ans;
}


//or
void getAns(int i, int j, vector<vector<int> > &dp, vector<int> &ans, vector<int> &cuts) {
	if (j - i <= 1)
		return ;

	for (int k = i + 1; k < j; k++) {
		if (dp[i][k] + dp[k][j] + cuts[j] - cuts[i] == dp[i][j]) {
			ans.push_back(cuts[k]);
			getAns(i, k, dp, ans, cuts);
			getAns(k, j, dp, ans, cuts);
			return ;
		}
	}
}

vector<int> Solution::rodCut(int n, vector<int> &cuts) {
	cuts.push_back(0), cuts.push_back(n);
	sort(cuts.begin(), cuts.end());
	vector<vector<int> > dp(cuts.size() + 1, vector<int> (cuts.size() + 1, 0));




	int N = cuts.size();

	for (int len = 2; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len - 1;

			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(cuts[j] - cuts[i] + dp[i][k] + dp[k][j], dp[i][j]);
		}
	}

	vector<int> ans;
	getAns(0, cuts.size() - 1, dp, ans, cuts);
	return ans;
}
