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
    int maxSum =0;
    int helper( TreeNode* root ){
        if( root==NULL ) return 0;

        int ls = max(0,helper( root->left));
        int rs =max( 0, helper(root->right));

        maxSum =max( maxSum , root->val + ls +rs);

        return root->val + max( ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
     
      return max( helper( root) , maxSum
      );

    }
};
