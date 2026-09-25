class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto &it:nums){
            mp[it]++;
        }
        int ans=0;
        for( auto &it:nums){
            if( mp.find(it-1)==mp.end()){
            int cnt=0;
            int num=it;
            while( mp.find(it)!=mp.end()){
                cnt++;
                it++;
            }
            ans =max(ans,cnt);
            }
        }
        return ans;
    }
};
