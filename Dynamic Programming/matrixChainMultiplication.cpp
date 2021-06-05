int mult(int arr[], int i , int j) {
    if (i >= j)
        return 0;

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = mult(arr, i, k) + mult(arr, k + 1, j)
                   + arr[i - 1] * arr[k] * arr[j];

        ans = min(ans, temp);
    }

    return ans;
}

int matrixMultiplication(int N, int arr[]) {
    return mult(arr, 1, N - 1);
}

// Memoized

int dp[101][101];

int multMemoized(int arr[], int i , int j) {
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = multMemoized(arr, i, k) + multMemoized(arr, k + 1, j)
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

//Tabular

int multTabular(int arr[], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]
                               + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }

    return dp[1][n - 1];
}
