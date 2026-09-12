class Solution {
   public:
    int helper(int idx, int amount, vector<vector<int>>& dp, vector<int>& coins) {
        if (idx < 0){
            if( amount==0)return 1;
            else return 0;
        }
        

        if (amount == 0) return 1;

        if (dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = helper(idx - 1, amount, dp, coins);
        int take = 0;
        if (amount >= coins[idx]) {
            take = helper(idx, amount - coins[idx], dp, coins);
        }

        return dp[idx][amount] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, dp, coins);
    }
};
