bool dp[101][101];

// void print(vector<int> &wt, int start, int sum, vector<int> &p, vector<vector<int>> &ans) {
// 	int n = wt.size();
// 	if (sum == 0) {
// 		ans.push_back(p);
// 		return ;
// 	}

// 	for (int i = start; i < n; i++) {
// 		if (wt[i] <= sum) {
// 			p.push_back(wt[i]);
// 			print(wt, i + 1, sum - wt[i], p, ans);

// 			p.pop_back();
// 		}
// 	}
// }


void print(vector<int> &wt, int i, int sum, vector<int> &p, vector<vector<int>> &ans) {
	if (sum == 0) {
		ans.push_back(p);
		return ;
	}

	if (wt[i - 1] <= sum && dp[i - 1][sum - wt[i - 1]]) {
		p.push_back(wt[i - 1]);
		print(wt, i - 1, sum - wt[i - 1], p, ans);
		p.pop_back();
	}

	if (dp[i - 1][sum]) {
		print(wt, i - 1, sum, p, ans);
	}


}



void printSubsetSumK(vector<int> wt, int target) {
	int n = wt.size();

	for (int j = 0; j < target + 1; j++) {
		dp[0][j] = 0;
	}

	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < target + 1; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = (dp[i - 1][j - wt[i - 1]]) || (dp[i - 1][j]);
			}

			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	vector<int> p;
	vector<vector<int>> ans;
	print(wt, n, target, p, ans);

	for (auto it : ans) {
		for (auto x : it)
			cout << x << " ";
		cout << endl;
	}

}


