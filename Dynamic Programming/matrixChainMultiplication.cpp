class Solution {
public:
    int dp[101][101];

    int mult(int arr[], int i , int j) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp = mult(arr, i, k) + mult(arr, k + 1, j)
                       + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int matrixMultiplication(int N, int arr[]) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++)
                dp[i][j] = -1;
        }
        return mult(arr, 1, N - 1);
    }
};