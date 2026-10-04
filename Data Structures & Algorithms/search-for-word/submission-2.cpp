class Solution {
   public:
    bool helper(int row, int col, int idx, string& word, vector<vector<char>>& board,
                unordered_set<int>& mp, int& m, int& n) {
        if (idx == word.size()) return true;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            int key = nr * n + nc;
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == word[idx] &&
                !mp.count(key)) {
                mp.insert(key);
                if (helper(nr, nc, idx + 1, word, board, mp, m, n)) return true;
                mp.erase(key);
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        unordered_set<int> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    int key = i * n + j;
                    mp.insert(key);
                    if (helper(i, j, 1, word, board, mp, m, n)) return true;
                    mp.erase(key);
                }
            }
        }

        return false;
    }
};
