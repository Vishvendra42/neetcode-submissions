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

class Solution {
   public:
    int count = 0;
    void helper(TreeNode* root, int maxi) {
        if (root == NULL) return;

        if (root->val >= maxi) {
            count++;
            
            maxi = root->val;
        }

        if (root->left != NULL) helper(root->left, maxi);
        if (root->right != NULL) helper(root->right, maxi);
        return;
    }
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return count;
    }
};
