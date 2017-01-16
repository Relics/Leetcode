class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = (int)nums.size();
        int ans = dfs(nums, 0, size-1);
        int sum = calSum(nums, 0, size-1);
        if (ans >= sum - ans) return true;
        return false;
    }
    int dfs(vector<int>& nums, int start, int end) {
        if (end < start) return 0;
        if (end == start) return nums[start];
        int sum = calSum(nums, start, end);
        // choose end
        int subAns1 = dfs(nums, start, end-1); // the maximum val the next player can get
        int myAns1 = sum - subAns1;
        // choose front
        int subAns2 = dfs(nums, start+1, end); // the maximum val the next player can get
        int myAns2 = sum - subAns2;
        return myAns1 >= myAns2 ? myAns1 : myAns2;
    }
    
    int calSum(vector<int>& nums, int start, int end) {
        int ans = 0;
        for (int i=start; i<=end; ++i)
            ans += nums[i];
        return ans;
    }
};