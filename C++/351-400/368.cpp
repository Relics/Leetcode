class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> res;
        if (size == 0) return res;
        vector<int> dp(size, 1);
        vector<int> pre(size, -1);
        int maxLastIndex = 0;
        int maxLen = 1;
        // dp equation: dp[i] = max(dp[j] + 1, dp[i]) if i % j == 0;
        sort(nums.begin(), nums.end());
        for (int i=1; i<size; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;    
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxLastIndex = i;
            }
        }
        for (int i=maxLastIndex; i>=0;) {
            res.push_back(nums[i]);
            i = pre[i];
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};