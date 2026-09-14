class Solution {
   public:
    int helper(int i1, int i2, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i1 < 0) return i2 + 1;
        if (i2 < 0) return i1 + 1;

        if( dp[i1][i2]!=-1)return dp[i1][i2];
        if (word1[i1] == word2[i2]) {
            return dp[i1][i2]=0 + helper(i1 - 1, i2 - 1, word1, word2, dp);
        }

        // replacement
        int rep = 1 + helper(i1 - 1, i2 - 1, word1, word2, dp);
        // deletion
        int del = 1 + helper(i1 - 1, i2, word1, word2, dp);
        // insertion
        int inser = 1 + helper(i1, i2 - 1, word1, word2, dp);

        return dp[i1][i2] = min({rep, del, inser});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp( word1.size() ,vector<int>( word2.size() ,-1));
        return helper( word1.size()-1 , word2.size()-1 , word1, word2, dp);
    }
};
