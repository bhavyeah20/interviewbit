class Solution {
public:
    int longestPalindromeSubseq(string x) {
        string y = x;
        reverse(y.begin(), y.end());

        int n = x.size(), m = y.size();

        int dp[n + 1][m + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];

    }
};

