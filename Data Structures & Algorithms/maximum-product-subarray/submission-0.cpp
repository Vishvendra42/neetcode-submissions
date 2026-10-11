class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n =nums.size();

        int ans=nums[0];

        int maxi =nums[0];
        int mini =nums[0];
         
        for( int i=1;i<n;i++){
           
          int a = maxi*nums[i];
          int b= mini*nums[i];

          maxi = max( { a,b,nums[i]});
          mini = min( { a,b,nums[i]});

          ans=max( maxi,ans);
          
        }

        return ans;

    }
};
