class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int fullxor =n;
        

        for (int i = 0; i < n; i++) {
            fullxor = fullxor ^ nums[i]^ i;
        }

        return fullxor;
    }
};
