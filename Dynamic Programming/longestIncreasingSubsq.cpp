// LCS with sorted unique

int Solution::lis(const vector<int> &A) {
	vector<int> a = A;
	sort(a.begin(), a.end());
	auto it = unique(a.begin(), a.end());
	a.resize(distance(a.begin(), it));

	int n = a.size(), m = A.size();
	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int j = 0; j < m + 1; j++)
		dp[0][j] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == A[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][m];


}


// Recur

class Solution {
public:

	int lis(vector<int> &A, int i, int prevElement) {
		if (i == A.size())
			return 0;

		int len1 = 0, len2 = 0;
		if (A[i] > prevElement) {
			len1 = 1 + lis(A, i + 1, A[i]);
		}

		len2 = lis(A, i + 1, prevElement);

		return max(len1, len2);
	}
	int lengthOfLIS(vector<int>& A) {
		return lis(A, 0, INT_MIN);
	}
};


// memoized

// dp[i][j]  => LIS from A[i] to end using A[j] as prevMax

class Solution {
public:

	int lis(vector<int> &A, int i, int idx, vector<vector<int> > &dp) {
		if (i == A.size())
			return 0;

		if (dp[i][idx] != -1)
			return dp[i][idx];

		int len1 = 0, len2 = 0;
		if (idx == 2501 || A[i] > A[idx]) {
			len1 = 1 + lis(A, i + 1, i, dp);
		}

		len2 = lis(A, i + 1, idx, dp);

		return dp[i][idx] = max(len1, len2);
	}
	int lengthOfLIS(vector<int>& A) {
		int n = A.size();
		vector<vector<int> > dp(n, vector<int> (2502, -1));
		return lis(A, 0, 2501, dp);
	}
};

// tabular O(n^2) * O(n)

// dp[i] = Len if LIS ending at A[i]


class Solution {
public:

	int lengthOfLIS(vector<int>& A) {
		int n = A.size();
		vector<int> dp(n, 1);
		int maxLen = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}

			maxLen = max(maxLen, dp[i]);
		}

		return maxLen;
	}



};

// O(nlogn) O(n)

class Solution {
public:

	int lengthOfLIS(vector<int>& A) {
		int n = A.size();
		vector<int> res;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(res.begin(), res.end(), A[i]);
			if (it == res.end())
				res.push_back(A[i]);

			else
				*it = A[i];
		}

		return res.size();
	}



};