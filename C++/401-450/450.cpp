// Solution 1 :reference : https://discuss.leetcode.com/topic/65792/recursive-easy-to-understand-java-solution/2
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                TreeNode* rightMin = findMinNode(root->right);
                root->val = rightMin->val;
                root->right = deleteNode(root->right, rightMin->val);
            }
        }
        return root;
    }
    TreeNode* findMinNode(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};


// Solution 2 : my solution, will make the BST tree's height be deeper.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (!root->right) return root->left;
            else if (!root->left) return root->right;
            else {
                TreeNode* rightMin = findMinNode(root->right);
                rightMin->left = root->left;
                return root->right;
            }
        }
        return root;
    }
    TreeNode* findMinNode(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};