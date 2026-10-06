class Solution {
   public:
    int m, n;
    void pacificFill(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& pacific) {
        pacific[row][col] = 1;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[row][col] ||
                pacific[nr][nc])
                continue;

            pacificFill(nr, nc, heights, pacific);
        }
        return;
    }
    void atlanticFill(int row, int col, vector<vector<int>>& heights,
                      vector<vector<int>>& atlantic) {
        atlantic[row][col] = 1;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[row][col] ||
                atlantic[nr][nc])
                continue;

            atlanticFill(nr, nc, heights, atlantic);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    pacificFill(i, j, heights, pacific);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 || j == n - 1) {
                    atlanticFill(i, j, heights, atlantic);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
