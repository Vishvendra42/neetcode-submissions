class Solution {
public:
    set<vector<int>>temp;
    void helper( int idx , int target , vector<int>&nums , vector<int>&order){
      if( target <0 || idx<0)return ;
      if( target==0) temp.insert( order);
      if( idx==0 ){
        if( target>=nums[idx]){
            order.push_back(nums[idx]);
            helper( idx ,target-nums[idx],nums,order);
            order.pop_back();
        }else return;
      }
      
      //skip
      helper( idx-1,target,nums,order);
      //take 
       if( target >=nums[idx]){
        order.push_back(nums[idx]);
        helper( idx ,target-nums[idx],nums,order);
        order.pop_back();
       }

       return ;
     
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        vector<int>order;
        helper( n-1,target,nums,order);
        vector<vector<int>>ans;
        for( auto &it:temp){
            ans.push_back( it);
        }

        return ans;
    }
};
