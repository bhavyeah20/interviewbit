class Solution {
public:
    int superEggDrop(int e, int f) {
        if (e == 1 || f == 0 || f == 1)
            return f;

        int ans = INT_MAX;
        for (int k = 1; k <= f; k++) {
            int temp = 1 + max(superEggDrop(e - 1, k - 1), superEggDrop(e, f - k));

            ans = min(ans, temp);
        }

        return ans;

    }
};

// memoized

class Solution {
public:

    int dp[101][10001];

    int superEggDropHelp(int e, int f) {
        if (e == 1 || f == 0 || f == 1)
            return f;

        if (dp[e][f] == -1) {
            int ans = INT_MAX;
            for (int k = 1; k <= f; k++) {
                if (dp[e - 1][k - 1] == -1)
                    dp[e - 1][k - 1] = superEggDropHelp(e - 1, k - 1);

                if (dp[e][f - k] == -1)
                    dp[e][f - k] = superEggDropHelp(e, f - k);

                int temp = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);

                ans = min(ans, temp);
            }
            dp[e][f] = ans;
        }


        return dp[e][f];

    }

    int superEggDrop(int e, int f) {
        memset(dp, -1, sizeof(dp));
        return superEggDropHelp(e, f);
    }
};

//memo + BS

class Solution {
public:

    int dp[101][10001];

    int superEggDropHelp(int e, int f) {
        if (e == 1 || f == 0 || f == 1)
            return f;

        if (dp[e][f] == -1) {
            int low = 1, high = f;
            int ans = INT_MAX;
            while (low <= high) {
                int mid = (low + high) / 2;

                if (dp[e - 1][mid - 1] == -1)
                    dp[e - 1][mid - 1] = superEggDropHelp(e - 1, mid - 1);


                if (dp[e][f - mid] == -1)
                    dp[e][f - mid] = superEggDropHelp(e, f - mid);

                int temp = max(1 + dp[e - 1][mid - 1], 1 + dp[e][f - mid]);

                if (dp[e - 1][mid - 1] < dp[e][f - mid])
                    low = mid + 1;

                else
                    high = mid - 1;

                ans = min(ans, temp);

            }

            dp[e][f] = ans;

        }
        return dp[e][f];

    }

    int superEggDrop(int e, int f) {
        memset(dp, -1, sizeof(dp));
        return superEggDropHelp(e, f);
    }
};


// BU + BS

class Solution {
public:

    int superEggDrop(int K, int N) {
        if (N == 0 || N == 1) return N; //Think for base case
        if (K == 1) return N;

        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 0));
        for (int i = 0; i <= K; i++)
            dp[i][0] = 0, dp[i][1] = 1; //Filling from base case as if N==0 ans=0 , N==1 ans=1
        for (int i = 0; i <= N; i++)
            dp[0][i] = 0, dp[1][i] = i; //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)

        for (int i = 2; i < K + 1; i++)
        {
            for (int j = 2; j < N + 1; j++)
            {   int l = 1, h = j, temp = 0, ans = 100000;
                while (l <= h)
                {
                    int mid = (l + h) / 2;
                    int left = dp[i - 1][mid - 1]; //egg broken check for down floors of mid
                    int right = dp[i][j - mid]; // not broken check for up floors of mid
                    temp = 1 + max(left, right);     //store max of both
                    if (left < right) {              //since right is more than left and we need more in worst case
                        l = mid + 1;                   // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward
                    {
                        h = mid - 1;
                    }
                    ans = min(ans, temp);            //store minimum attempts
                }
                dp[i][j] = ans;
            }
        }
        return dp[K][N];

    }
};