class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void dfs(int depth, int usedNumber, int k, int target){
        if (depth >= 10 || usedNumber >= k || target <= 0) {
            if (target == 0 && usedNumber == k) ans.push_back(temp);
            return;
        }
        if (target < depth) return;
        temp.push_back(depth);
        dfs(depth+1, usedNumber+1, k, target-depth);
        temp.pop_back();
        dfs(depth+1, usedNumber, k, target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 0, k, n);
        return ans;
    }
};