class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1])
                                      + triangle[row][col];
            }
        }
        return dp[0][0];
    }
};