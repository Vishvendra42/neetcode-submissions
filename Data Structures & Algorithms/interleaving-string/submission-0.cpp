class Solution {
   public:
    bool helper(int i, int j, string& s1, string& s2, string& s3,vector<vector<int>>&dp) {
        int k = i + j;
        if (k == s3.size()) return true;
          
        if( dp[i][j]!=-1)return dp[i][j];
        bool take1 = false;
        bool take2 =false;
        if (i<s1.size() && s1[i] == s3[k] ) {
           take1= helper(i + 1, j, s1, s2, s3,dp);
        }
        if (j<s2.size() && s2[j] == s3[k] ) {
           take2= helper(i, j + 1, s1, s2, s3,dp);
        }

        return dp[i][j]=take1 || take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>>dp( s1.size()+1,vector<int>( s2.size()+1,-1));
          return helper( 0,0,s1,s2,s3,dp);
       
    }
};
