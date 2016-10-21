class Solution {
private:
    vector<vector<int>> ans;
    set<vector<int>> mySet;
    vector<int> temp;
public:
    void dfs(vector<int>& candidates, int depth, int target) {
        if (target<=0 || depth >= (int)candidates.size()) {
            if (target == 0) mySet.insert(temp);
            return;
        }
        if (candidates[depth] > target) return;
        temp.push_back(candidates[depth]);
        dfs(candidates, depth+1, target-candidates[depth]);
        temp.pop_back();
        dfs(candidates, depth+1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        for (auto i:mySet) {
            ans.push_back(i);
        }
        return ans;
    }
};