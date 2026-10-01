class Solution {
public:
    int helper(int idx,  int buyday , vector<int>&prices ){
        if( idx>=prices.size() )return 0;
     

        int skip =  helper( idx+1 , buyday ,prices);
        int profit =0;
        int buy =0;
        if( buyday!=-1){
            // already buyed so sell today
            profit = prices[idx] - prices[buyday];
        }else {
            // if not buyed then buy today 
            buy = helper( idx+1 , idx, prices);
        }

        return max( { skip , profit , buy});
    }
    int maxProfit(vector<int>& prices) {
        return helper( 0 , -1, prices);
    }
};
