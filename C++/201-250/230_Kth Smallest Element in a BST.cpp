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
private:
    int index;
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        index = 0;
        ans = 0;
        solve(root, k);
        return ans;
    }
    void solve(TreeNode* root, int k) {
        if (root == NULL) return;
        else {
            solve(root->left, k);
            if (++index == k) {
                ans = root->val;
                return;
            }
            solve(root->right, k);
        }
    }
};