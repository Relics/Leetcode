class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums=nums;
    }
    int pick(int target) {
        int output=-1;
        int count=0;
        for (int i=0; i<(int)nums.size(); ++i) {
            if (nums[i] != target) continue;
            ++count;
            if (rand() % count == 0) output = i;
        }
        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */