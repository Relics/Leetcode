/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Reference: http://blog.csdn.net/qq508618087/article/details/50886124
// Wrong answer
class Solution {
private:
    TreeNode* pre = NULL, * ans = NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return root;
        inorderSuccessor(root->left, p);
        if (pre == p) {
            ans = root;
            return ans;  
            // The reason why it was wrong
            // Since the recursion won't stop and we know that, after this return,
            // the pre won't be updated again and the ans will be overrid
        }
        pre = root;
        inorderSuccessor(root->right, p);
        return ans;
    }
};

// AC 1
class Solution {
private:
    TreeNode* pre = NULL, * ans = NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return root;
        inorderSuccessor(root->left, p);
        if (pre == p) {
            ans = root;
            return ans;  
        }
        pre = root;
        inorderSuccessor(root->right, p);
        return ans;
    }
};

// AC 2
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p || !root) return NULL;
        TreeNode* ans=NULL;
        while (root) {
            if (root->val > p->val) {
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};

