class Solution {
public:

    int minCoinsRecursion(vector<int> &coins, int n, int amt) {
        if (!amt)
            return 0;

        if (!n)
            return -1;

        if (coins[n - 1] <= amt)
            return min(1 + minCoinsRecursion(coins, n, amt - coins[n - 1]),
                       minCoinsRecursion(coins, n - 1, amt));

        else
            return minCoinsRecursion(coins, n - 1, amt);
    }

    int minCoins(vector<int> &coins, int n, int amt) {

        int dp[n + 1][amt + 1];

        for (int j = 0; j < amt + 1; j++)
            dp[0][j] = INT_MAX - 1;

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;


        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amt + 1; j++) {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amt] == INT_MAX - 1 ? -1 : dp[n][amt];
    }


    int minCoinsSpaceOptimised(vector<int> &coins, int n, int amt) {

        int dp[amt + 1];

        for (int i = 0; i < amt + 1; i++)
            dp[i] = INT_MAX - 1;


        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i < amt + 1; i++)
                dp[i] = min(1 + dp[i - coin], dp[i]);

        }

        return dp[amt] == INT_MAX - 1 ? -1 : dp[amt];
    }

    int coinChange(vector<int>& coins, int amt) {
        return minCoinsSpaceOptimised(coins, coins.size(), amt);
    }
};