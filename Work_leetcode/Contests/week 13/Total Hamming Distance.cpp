class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int counts[32] = {0};
        for (int num : nums) {
            int temp = 0;
            while (num) {
                if (num & 1) ++counts[temp];
                num >>= 1;
                ++temp;
            }
        }
        int ans = 0, size = (int)nums.size();
        for (int i=0; i<32; ++i) {
            if (counts[i]) {
                ans += counts[i] * (size - counts[i]);    
            }
        }
        return ans;
    }
};