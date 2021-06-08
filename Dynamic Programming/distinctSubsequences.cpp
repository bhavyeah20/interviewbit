int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();

    int dp[n + 1][m + 1];

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][m];


}





public int numDistinct(String s, String t) {
    int m = s.length(), n = t.length();
    int[][] dp = new int[m + 1][n + 1];
    // initialize the dp value when t is an empty string, number of subsequence of an empty string should be 1
    for (int i = 0; i < m; i ++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            //in both cases, the subsequence in String t should be ending with character t.charAt(j - 1)
            if (s.charAt(i - 1) == t.charAt(j - 1)) {
                // when two pointers pointing to same character
                // if we take these two characters simultaneously, we should have dp[i-1][j-1] subsequences
                // otherwise if we overlook current i (moving back for one step) and keeping the current j we have another dp[i -1][j]
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                // when two pointers pointing to difference characters
                //we cannot take these two characters but we still should make j ending with pointing to current position
                // then we should move i backward
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}