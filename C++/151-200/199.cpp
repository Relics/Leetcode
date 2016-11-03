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
    void helper(TreeNode* root, int deep, vector<int>& result) {
        if (!root) return;
        else {
            if (deep >= (int)result.size()) {
                result.push_back(root->val);
                if (root->right)
                    helper(root->right, deep+1, result);
                if (root->left)
                    helper(root->left, deep+1, result);
            } else {
                if (root->right)
                    helper(root->right, deep+1, result);
                if (root->left)
                    helper(root->left, deep+1, result);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, 0, result);
        return result;
    }
};