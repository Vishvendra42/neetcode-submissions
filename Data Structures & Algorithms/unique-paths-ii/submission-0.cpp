class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size();
        int  n =obstacleGrid[0].size();
          vector<vector<int>>dp(m,vector<int>(n,0));
         bool obstracle=false;
        for( int i =0;i<n;i++){
            if( obstacleGrid[0][i]==1 ) break;
            dp[0][i]=1;

        }
        obstracle=false;
        for( int i=0;i<m;i++){
            if( obstacleGrid[i][0]==1 ) break;
            dp[i][0]=1;
        }

        for( int row =1;row<m;row++){

            for( int col =1; col<n;col++){
                if(  obstacleGrid[row][col]==1) continue;
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[m-1][n-1];
    }
};