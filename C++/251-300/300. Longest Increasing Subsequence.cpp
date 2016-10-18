// O(n^2) way
// Use simple dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> dp(size,1);
        for (int i=1; i<size; ++i) {
            int maxlen = 1;
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    maxlen = max(maxlen, dp[j]+1);
                }
            }
            dp[i] = maxlen;
        }
        int ans = 0;
        for (int i=0; i<size; ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};

// O(nlogn) way
// Use binary seach of the increasing array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int numSize = (int)nums.size();
        for (int i=0; i<numSize; ++i) {
            if (i == 0) dp.push_back(nums[i]);
            else {
                if (nums[i] > dp.back()) {
                    dp.push_back(nums[i]);
                } else {
                    auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                    *it = nums[i];
                }
            }
        }
        return (int)(dp.size());
    }
};
