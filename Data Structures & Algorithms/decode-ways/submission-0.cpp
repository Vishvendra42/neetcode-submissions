class Solution {
   public:
    int helper(int idx, string&s, vector<int>& dp) {
        if (idx < 0) return 1;

        if (dp[idx] != -1) return dp[idx];
        int ans = 0;
        // taking current digit
        if (s[idx] != '0') {
            ans += helper(idx - 1, s, dp);
        }

        // taking current and prev onne
        if (idx > 0) {
            int num = stoi(s.substr(idx - 1, 2));
            if (num >= 10 && num <= 26) {
                ans += helper(idx - 2, s, dp);
            }
        }

        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return helper(n -1, s, dp);
    }
};
