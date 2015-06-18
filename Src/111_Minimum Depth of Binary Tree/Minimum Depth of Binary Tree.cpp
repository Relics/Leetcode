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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==right&&left==0)
            return 1;
        if(left==0)
            left=INT_MAX;
        if(right==0)
            right=INT_MAX;
        return (left<right)?(left+1):(right+1);
    }
};