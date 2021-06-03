class Solution {
public:

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
            int t = 1 + minimumCuts(s, i, k, dp) + minimumCuts(s, k + 1, j, dp);

            ans = min(ans, t);

        }
        dp[i][j] = ans;
        return dp[i][j];

    }

    int minCut(string s) {
        int n = s.size();
        if (isPalindrome(s, 0, n - 1))
            return 0;


        int **dp = new int*[n];
        for (int i = 0; i < n; i++)
            dp[i] = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        }

        return minimumCuts(s, 0, n - 1, dp);
    }
};


// class Solution {
// public:

//     bool isPalindrome(string s, int i , int j) {
//         while (i < j) {
//             if (s[i] != s[j])
//                 return 0;
//             i++, j--;
//         }

//         return 1;
//     }

//     int minimumCuts(string s, int i , int j) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++)
//                 dp[i][j] = 0;
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (isPalindrome(s, i, j))
//                     dp[i][j] = 0;
//             }
//         }

//         int ans = INT_MAX;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = i; k < j; k++) {
//                     int t = 1 + dp[i][k] + dp[k + 1][j];
//                     ans = min(ans, t);
//                 }
//                 dp[i][j] = ans;
//             }
//         }

//         return dp[0][n - 1];
//     }

//     int minCut(string s) {
//         int n = s.size();
//         if (isPalindrome(s, 0, n - 1))
//             return 0;
//         return minimumCuts(s, 0, n - 1);
//     }
// };