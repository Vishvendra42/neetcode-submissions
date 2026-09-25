class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        for(auto &it:s ){
            count[it-'a']++;
        }
        for(auto &it:t){
            if(count[it-'a']==0)return false;
            count[it-'a']--;
        }
        for(auto &it: count){
            if(it!=0)return false;
        }
        return true;
    }
};
