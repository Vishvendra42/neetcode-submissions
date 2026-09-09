class Solution {
   public:
    
    bool find(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, false));
        dp[0][nums[0]] = true;
         dp[0][0]=true;
        for (int i = 1; i < n; i++) {
            dp[i][0] = true;
            for (int sum = 0; sum <= target; sum++) {

                bool take = false;
                if (nums[i] <= sum) take = dp[i-1][sum-nums[i]];
                bool notTake = dp[i-1][sum];

                dp[i][sum] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int  sum =0;
        for( auto it:nums) sum+=it;

        if( sum%2==1)return false;
        return find( nums , sum/2);
    }
};
