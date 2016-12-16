// https://discuss.leetcode.com/topic/4661/c-solution-and-explanation/2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        for (int i=0; i<size;) {
            int counts = 0;
            while (i + counts < size && nums[counts + i] == nums[i]) ++counts;
            int previousSize = result.size();
            for (int j=0; j <previousSize; ++j) {
                vector<int> instance = result[j];
                for (int k = 0; k < counts; ++k) {
                    instance.push_back(nums[i]);
                    result.push_back(instance);
                }
            }
            i += counts;
        }
        return result;
    }
};