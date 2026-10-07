class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        for( int i=0;i<n;i++){
            if( i==n-1)return true;
            if( !nums[i])return false;
        int step=nums[i];
        nums[i+1] = max( nums[i+1] , step-1);
        }
        return false;
    }
};
