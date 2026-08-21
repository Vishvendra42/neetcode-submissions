/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

   string serialize(TreeNode* root) {
        string Serialized = "";
        if (root == NULL)
            return Serialized;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                Serialized += "#,";
                continue;
            }
            Serialized += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return Serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                temp->left = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(str));
                temp->left = node;
                q.push(node);
            }

            getline(s, str, ',');
            if (str == "#") {
                temp->right = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(str));
                temp->right = node;
                q.push(node);
            }
        }
        return root;
    }
};
