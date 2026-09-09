class Solution {
   public:
   
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
       int total =accumulate( nums.begin() , nums.end() ,0);

       if( abs(target) > total || (total+ target )%2==1) return 0;

       int req = (total+ target)/2;
       
       vector<int>prev( req+1 , 0);
       prev[0]=1;

       if(nums[0]<=req){
        prev[nums[0]]+=1;
       }

       for( int i =1;i<n;i++){
        vector<int>curr( req+1,0);
        for( int t =0;t<=req;t++){
            int take =0;
            if( nums[i]<=t){
                take = prev [t-nums[i]];
            }
            int notTake =prev[t];

            curr[t]= take+notTake;
        }
        prev=curr;
       }
       return prev[req];
    }
};
