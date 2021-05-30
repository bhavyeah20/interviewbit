O(wt * t), O(wt * t)

class Solution {
public:
	int dp[201][10001];

	int subsetSumTabular(vector<int> wt, int target, int n) {

		for (int j = 0; j < target + 1; j++) {
			dp[0][j] = 0;
		}

		for (int i = 0; i < n + 1; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < target + 1; j++) {
				if (wt[i - 1] <= j) {
					dp[i][j] = (dp[i - 1][j - wt[i - 1]]) || (dp[i - 1][j]);
				}

				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		return dp[n][target];
	}


	bool canPartition(vector<int>& nums) {

		int target = 0;
		for (int x : nums)
			target += x;

		if (target & 1)
			return 0;
		return subsetSumTabular(nums, target / 2, nums.size());
	}
};

//or

O(wt * t), O(t)

public boolean canPartition(int[] nums) {
	int sum = 0;

	for (int num : nums) {
		sum += num;
	}

	if ((sum & 1) == 1) {
		return false;
	}
	sum /= 2;

	int n = nums.length;
	boolean[] dp = new boolean[sum + 1];
	Arrays.fill(dp, false);
	dp[0] = true;

	for (int num : nums) {
		for (int i = sum; i > 0; i--) {
			if (i >= num) {
				dp[i] = dp[i] || dp[i - num];
			}
		}
	}

	return dp[sum];
}