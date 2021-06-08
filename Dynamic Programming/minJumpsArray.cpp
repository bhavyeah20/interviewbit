int Solution::jump(vector<int> &A) {
	int n = A.size();
	vector<int> dp(n, INT_MAX - 1);
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (j + A[j] >= i)
				dp[i] = min(dp[i], 1 + dp[j]);
		}

		if (dp[i] == INT_MAX - 1)
			return -1;
	}

	return dp[n - 1];
}

//

class Solution {
public:
	int jump(vector<int>& A) {
		int n = A.size();
		queue<pair<int, pair<int, int>> > q;
		pair<int, pair<int, int>> ans;
		// min jumps,idx,jumps from A[i]
		q.push({0, {0, A[0]}});

		for (int i = 1; i < n; i++) {
			pair<int, pair<int, int>> f = q.front();
			while (!q.empty() && f.second.first + f.second.first < i) {
				q.pop();
				if (!q.empty())
					f = q.front();
			}
			if (q.empty())
				return -1;

			ans = {f.first + 1, {i, A[i]}};
			q.push(ans);

		}

		return ans.first;
	}

};