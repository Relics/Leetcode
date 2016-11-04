class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int size = (int)nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-2; ++i) {
            int l = i+1, r = size-1;
            int remain = target - nums[i];
            while (l < r) {
                if (nums[r] + nums[l] < remain) {
                    ans += r-l; 
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans;
    }
};