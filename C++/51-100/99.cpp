/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Reference: https://www.tianmaying.com/tutorial/LC99
class Solution {
private:
	TreeNode* first = NULL, *second = NULL, *prev = NULL;
public:
    void recoverTree(TreeNode* root) {
    	inorder(root);
    	if (first && second) {
    		int temp = first->val;
    		first->val = second->val;
    		second->val = temp;
    	}
    }
    void inorder(TreeNode* root) {
    	if (!root) return;
    	inorder(root->left);
    	if (prev && root->val < prev->val) {
    		if (first == NULL) {
    			first = prev;
    			second = root;
    		} else {
    			second = root;
    		}
    	}
    	prev = root;
    	inorder(root->right);
    }
};