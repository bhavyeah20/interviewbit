int ways(string s, int i, int j, bool T) {


    if (i == j) {
        if (T)
            return s[i] == 'T' ? 1 : 0;
        return s[i] == 'T' ? 0 : 1;
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2) {
        int lT = ways(s, i, k - 1, true), rT = ways(s, k + 1, j, true);
        int lF = ways(s, i, k - 1, false), rF = ways(s, k + 1, j, false);

        if (s[k] == '&') {
            if (T)
                ans += lT * rT;
            else
                ans += lT * rF + lF * rT + lF * rF;
        }
        else if (s[k] == '|') {
            if (T)
                ans += lT * rF + lF * rT + lT * rT;
            else
                ans += lF * rF;
        }

        else {
            if (T)
                ans += lT * rF + lF * rT;
            else
                ans += lF * rF + + lT * rT;
        }

    }
    return ans;
}
int countWays(int N, string s) {
    return ways(s, 0, N - 1, true);
}

// Memoized


int dp[201][201][2];
int mod = 1003;

int ways(string s, int i, int j, bool T) {

    if (i == j) {
        if (T)
            return s[i] == 'T' ? 1 : 0;
        return s[i] == 'T' ? 0 : 1;
    }

    int ans = 0;

    if (dp[i][j][T] != -1)
        return dp[i][j][T];

    for (int k = i + 1; k < j; k += 2) {
        if (dp[i][k - 1][1] == -1)
            dp[i][k - 1][1] = ways(s, i, k - 1, 1) % mod;

        if (dp[i][k - 1][0] == -1)
            dp[i][k - 1][0] = ways(s, i, k - 1, 0) % mod;


        if (dp[k + 1][j][1] == -1)
            dp[k + 1][j][1] = ways(s, k + 1, j, 1) % mod;


        if (dp[k + 1][j][0] == -1)
            dp[k + 1][j][0] = ways(s, k + 1, j, 0) % mod;


        if (s[k] == '&') {
            if (T)
                ans += dp[i][k - 1][1] * dp[k + 1][j][1];
            else
                ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][0] * dp[k + 1][j][0];
        }
        else if (s[k] == '|') {
            if (T)
                ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][1];
            else
                ans += dp[i][k - 1][0] * dp[k + 1][j][0];
        }

        else {
            if (T)
                ans += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1];
            else
                ans += dp[i][k - 1][0] * dp[k + 1][j][0] + + dp[i][k - 1][1] * dp[k + 1][j][1];
        }

    }
    return dp[i][j][T] = ans % mod ;
}

int countWays(int N, string s) {
    memset(dp, -1, sizeof(dp));
    return ways(s, 0, N - 1, true);
}