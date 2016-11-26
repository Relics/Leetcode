/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // We need to use BFS to solve this problem
class Solution {
private:
    vector<vector<int>> result;
    map<int, vector<int>> m;
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto f = q.front();
            q.pop();;
            m[f.second].push_back(f.first->val);
            if (f.first->left) q.push(make_pair(f.first->left, f.second-1));
            if (f.first->right) q.push(make_pair(f.first->right, f.second+1));
        }
        for (auto i : m) {
            result.push_back(i.second);
        }
        return result;    
    }
};