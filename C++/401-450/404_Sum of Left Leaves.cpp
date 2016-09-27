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
    int solve(TreeNode* root, bool isLeftLeaves){
        if (!root) return 0;
        if (!root->left && !root->right && isLeftLeaves){
            return root->val;
        }else{
            int ans=0;
            if (root->left)
                ans+=solve(root->left, true);
            if (root->right)
                ans+=solve(root->right, false);
            return ans;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};