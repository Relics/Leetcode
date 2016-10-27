// Reference: http://bookshadow.com/weblog/2016/03/13/leetcode-house-robber-iii/

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
    vector<int> solve(TreeNode* root){
        vector<int> ans = {0, 0};
        if (root) {
            vector<int> lchild = solve(root->left);
            vector<int> rchild = solve(root->right);
            ans[0] = max(lchild[0], lchild[1]) + max(rchild[1],rchild[0]);
            ans[1] = lchild[0] + rchild[0] + root->val;
        }
        return ans;
    }
    int rob(TreeNode* root) {
        vector<int> temp = solve(root);
        return max(temp[0], temp[1]);
    }
};