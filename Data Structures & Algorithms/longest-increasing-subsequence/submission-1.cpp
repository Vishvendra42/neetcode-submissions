class Solution {
   public:
    int helper(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        // base case
        if (idx == nums.size()) return 0;

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int notTake = helper(idx + 1, prev, nums, dp);

        int take = 0;

        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + helper(idx + 1, idx, nums, dp);
        }

        return dp[idx][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for (int i =0 ; i <n; i++) {
            for (int j = 0; j < i; j++) {
                    if( nums[j] < nums[i]){
                        dp[i] = max( dp[i] , dp[j]+1);
                    }

            
                
            }
            maxi =max(dp[i],maxi);
        }
        return maxi;
    }
};
