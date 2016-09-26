/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)    
            return root;
        else
            solve(root);
        return root;
    }
    void solve(TreeNode *root){
        if(root==NULL)
            return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        solve(root->left);
        solve(root->right);
    }
};