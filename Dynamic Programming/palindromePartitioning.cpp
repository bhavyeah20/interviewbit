bool isPalindrome(string s, int i , int j) {
    while (i < j) {
        if (s[i] != s[j])
            return 0;
        i++, j--;
    }

    return 1;
}

int minimumCuts(string s, int i , int j, int **dp) {
    if (i >= j)
        return 0;

    if (isPalindrome(s, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {


        if (dp[i][k] == -1)
            dp[i][k] = minimumCuts(s, i, k, dp);

        if (dp[k + 1][j] == -1)
            dp[k + 1][j] = minimumCuts(s, k + 1, j, dp);

        int t = 1 + dp[i][k] + dp[k + 1][j];

        ans = min(ans, t);

    }
    dp[i][j] = ans;
    return dp[i][j];

}

int minCut(string s) {
    int n = s.size();

    int **dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    return minimumCuts(s, 0, n - 1, dp);
}

// Tabulation

int minCut(string s) {
    int N = s.size();
    int dp[N][N];
    bool p[N][N];
    memset(p, 0, sizeof(p));


    for (int i = 0; i < N; i++)
        dp[i][i] = 0, p[i][i] = 1;

    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N - L; i++) {
            int j = i + L - 1;
            dp[i][j] = 2001;

            if (L == 2) {
                if (s[i] == s[j]) {
                    p[i][j] = 1;
                    dp[i][j] = 0;
                }
            }

            else {
                if (s[i] == s[j] && p[i + 1][j - 1])
                    dp[i][j] = 0, p[i][j] = 1;
            }

            if (dp[i][j] == 0)
                continue;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                               1 + dp[i][k] + dp[k + 1][j]);
            }
        }
    }


    return dp[0][N - 1];
}

// or

int minCut(string s) {
    int N = s.size();
    int dp[N];
    bool p[N][N];
    memset(p, 0, sizeof(p));

    for (int L = 0; L <= N; L++) {
        for (int i = 0, j = L; j < N; i++, j++) {
            if (L == 0)
                p[i][j] = 1;

            else if (L == 1)
                p[i][j] = s[i] == s[j] ? 1 : 0;

            else {
                if (s[i] == s[j] && p[i + 1][j - 1])
                    p[i][j] = 1;
            }
        }
    }

    dp[0] = 0;

    for (int j = 1; j < N; j++) {
        dp[j] = 2001;
        if (p[0][j]) {
            dp[j] = 0;
            continue;
        }
        for (int i = 1; i <= j; i++) {
            if (p[i][j]) {
                dp[j] = min(dp[j], 1 + dp[i - 1]);
            }
        }
    }

    return dp[N - 1];
}