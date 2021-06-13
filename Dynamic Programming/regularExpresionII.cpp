class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(n + 1, vector<bool> (m + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i < n + 1; i++) {
            if (p[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s[j - 1] == p[i - 1] || p[i - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];

                    if (dp[i][j])
                        continue;

                    if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }


};


// mis* -> mi or mis s*
//s[j] = p[i] top left, p[i] = '.' top left, if p[i] = '*', two above(* -> 0 mi) or one left (mis s*)