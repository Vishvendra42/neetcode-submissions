class Solution {
   public:
    int helper(int idx, vector<int>& arr, int sum, vector<vector<int>>& dp, int maxsum) {
        if (idx < 0) {
            if (sum == 0) return 1;
            return 0;
        }

        // Impossible state
        if (abs(sum) > maxsum) return 0;

        if (dp[idx][sum + maxsum] != -1) return dp[idx][sum + maxsum];

        int add = helper(idx - 1, arr, sum - arr[idx], dp, maxsum);
        int sub = helper(idx - 1, arr, sum + arr[idx], dp, maxsum);

        return dp[idx][sum + maxsum] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) sum += abs(it);
        if (abs(target) > sum) return 0;
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return helper(n - 1, nums, target, dp, sum);
    }
};
