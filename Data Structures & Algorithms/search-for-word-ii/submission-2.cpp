class TreeNode {
   public:
    bool isEnd;
    TreeNode* children[26];

    TreeNode() {
        for (auto& it : children) {
            it = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
   public:
    int n, m;
    vector<string> ans;
    void dfs(int row, int col, vector<vector<char>>& board, string& word, TreeNode* node) {
        if (node->isEnd ) {
           ans.push_back(word);
           
           //avoid duplicate
           node->isEnd =false;
        }

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] != '#') {
                char ch = board[nr][nc];
                if (node->children[ch - 'a'] != nullptr) {
                    word.push_back(ch);
                    board[nr][nc] = '#';
                    dfs(nr, nc, board, word, node->children[ch - 'a']);
                    board[nr][nc] = ch;
                    word.pop_back();
                }
            }
        }

        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TreeNode* root = new TreeNode();

        for (auto& word : words) {
            TreeNode* node = root;
            for (auto& it : word) {
                if (node->children[it - 'a'] == nullptr) {
                    node->children[it - 'a'] = new TreeNode();
                }

                node = node->children[it - 'a'];
            }
            node->isEnd = true;
        }

        // now we have a trie that contain all the words

        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                TreeNode* node = root;
                char ch = board[i][j];
                if (node->children[ch - 'a'] != nullptr) {
                    string word = "";
                    word += ch;
                    if( node->isEnd) ans.push_back(word);
                    board[i][j]='#';
                    dfs(i, j, board, word, node->children[ch - 'a']);
                    board[i][j]=ch;
                }
            }
        }

       
        return ans;
    }
};
