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
    vector<int> sums;
    vector<int> nums;
public:
    int traverse1(TreeNode* s) {
        if (!s) return 0;
        else {
            int sum = traverse1(s->right) + traverse1(s->left) + s->val;
            sums.push_back(sum);
            return sum; 
        }
    }
    int traverse2(TreeNode* s) {
        if (!s) return 0;
        else {
            int nodeNum = traverse2(s->right) + traverse2(s->left) + 1;
            return nodeNum;
        }
    }
    bool solve(TreeNode* t, int& i, int sum, int num) {
        if (!t || nums[i] < num) return false;
        bool f1, f2, f3, f4;
        int tt = i;
        if (nums[i] == num && sums[i] == sum) {
            f1 = solve(t->left, ++i, sum-t->val, num-1);
            f2 = solve(t->right, ++i, sum-t->val, num-1);
        }
        f3 = solve(t->left, tt, sum, num);
        f4 = solve(t->right, tt, sum, num);
        return true;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        traverse1(s);
        reverse(sums.begin(), sums.end());
        traverse2(s);
        reverse(nums.begin(), nums.end());
        int sum_t = traverse1(t);
        int nodeNum_t = traverse2(t);
        int i = 0;
        return solve(t, i, sum_t, nodeNum_t);
    }
};