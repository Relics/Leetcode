class Solution {
public:
    int foobar(vector<int>& nums, int S) {
        int ans = 0;
        unordered_map<int, int> umap;
        for (auto num : nums) {
            unordered_map<int, int> now;
            if (umap.empty()) {
                ++umap[num];
                ++umap[-num];
                continue;
            } else {
                for (auto it = umap.begin(); it != umap.end(); ++it) {
                    int mapnum = it -> first;
                    int counts = it -> second;
                    now[mapnum + num] += counts;
                    now[mapnum - num] += counts;
                }
            }
            umap = now;
        }
        return umap[S];
    }
};