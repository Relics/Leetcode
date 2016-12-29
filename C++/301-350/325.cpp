class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int temp = 0, size = (int)nums.size(), ans = 0;
        for (int i=0; i<size; ++i) {
            temp += nums[i];
            if (umap.count(temp-k)) {
                ans = max(ans, i-umap[temp-k]);
            }
            if (!umap.count(temp)) umap[temp] = i;
        }
        return ans;
    }
};