class Solution {
public:
    int findTargetSumWays(vector<int>& wt, int t) {
        int n = wt.size();
        int diff = t;
        int sum = 0, cnt = 0;
        for (int num : wt) {
            sum += num;

            if (!num) cnt++;
        }

        t = diff + sum;

        if (t & 1)
            return 0;


        t /= 2;

        int dp[n + 1][t + 1];
        for (int j = 0; j < t + 1; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }


        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < t + 1; j++) {
                if (wt[i - 1] <= j && wt[i - 1] != 0) {
                    dp[i][j] = dp[i - 1][j - wt[i - 1]] + dp[i - 1][j];
                }

                else
                    dp[i][j] = dp[i - 1][j];

            }
        }

        return dp[n][t] * pow(2, cnt);

    }

};



