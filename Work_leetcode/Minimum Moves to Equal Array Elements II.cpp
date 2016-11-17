class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int size = (int)nums.size();
        if (size == 1) return 0;
        int key = nums[size/2];
        int ans = 0;
        for (int i=0; i<size; ++i) ans += abs(nums[i]-key);
        return ans;
    }
};