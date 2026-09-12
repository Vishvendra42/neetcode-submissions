class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if( amount==0)return 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1,0));
        // base case
         for( int amnt =0 ;amnt<=amount ;amnt++){
            if( amnt %coins[0]==0){
            dp[0][amnt] = amnt/coins[0] ;
            }else{
                dp[0][amnt]=INT_MIN;
            }
         }
        for (int row = 1; row < n; row++) {
            for (int amnt = 0; amnt <= amount; amnt++) {

             int notTake = dp[row-1][amnt];
             int take =INT_MIN;
             if( amnt >= coins[row]){
                take = dp[row][amnt-coins[row]] +1;
             }  
              
              if( take<0) {
                dp[row][amnt] = notTake;
                continue;
              }
              if( notTake <0){
                dp[row][amnt] =take ;
                continue;
              }

             dp[row][amnt]= min( take ,notTake);
            }
        }
        if( dp[n-1][amount] <0)return -1;
        return dp[n-1][amount];
    }
};
