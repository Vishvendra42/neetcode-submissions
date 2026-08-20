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
    int diam=0;
    int depth( TreeNode*root, int &diam){
        if(root==NULL) return 0;
       
       int lh=0,rh=0;
       if(root->left!=NULL){
        lh = depth(root->left,diam);
       }
       if(root->right!=NULL){
        rh = depth(root->right,diam);
       }

       diam = max( diam , lh+rh);
       return max( lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth( root,diam);
        return diam;
    }
};
