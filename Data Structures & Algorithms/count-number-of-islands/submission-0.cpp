class Solution {
   public:
    int n, m;
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n ||grid[nr][nc]=='0'|| vis[nr][nc]) continue;

            dfs(nr, nc, grid, vis);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] =='1'&& vis[i][j] == 0 ) {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};
