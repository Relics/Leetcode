class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void dfs (vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i=start; i<(int)candidates.size(); ++i) {
            if (candidates[i] > target) return;
            temp.push_back(candidates[i]);
            dfs (candidates, target-candidates[i], i+1);
            temp.pop_back();
            while (candidates[i+1] == candidates[i]) ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end());
        dfs (candidates, target, 0);
        return ans;
    }
};