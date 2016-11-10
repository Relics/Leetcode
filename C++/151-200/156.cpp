/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Reference:
// https://discuss.leetcode.com/topic/40924/java-recursive-o-logn-space-and-iterative-solutions-o-1-space-with-explanation-and-figure/2
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode* newHead = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root; 
        root->left = NULL;
        root->right = NULL;
        return newHead;
    }
};