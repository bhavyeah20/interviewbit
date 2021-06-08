class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (!dp[i])
                return false;

            for (int j = 0; j <= nums[i]; j++)
                dp[j] = 1;

            if (dp[n - 1])
                return true;
        }

        return true;
    }
};


//

int Solution::canJump(vector<int> &nums) {
    int reach = 0;
    int n = nums.size();
    for (int i = 0; i < n && i <= reach; i++)
        reach = max(reach, nums[i] + i);

    return reach >= n - 1;
}