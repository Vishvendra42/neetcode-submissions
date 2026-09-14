class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        while (i < n) {
            int f = target - nums[i];
             if (mp.find(f) != mp.end()) { return {mp[f] ,i}; }
            mp[nums[i]] = i;
            i++;
        }
        return {};
    }
};
