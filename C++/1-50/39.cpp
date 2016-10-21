class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void dfs(vector<int>& candidates, int depth, int target) {
        if (depth == (int)candidates.size() || target <= 0) {
            if (target == 0) ans.push_back(temp);
            return;
        }
        if (candidates[depth] > target) return;
        temp.push_back(candidates[depth]);
        dfs(candidates, depth, target-candidates[depth]);
        temp.pop_back();
        dfs(candidates, depth+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};