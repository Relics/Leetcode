// Solution 1
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int size = (int)nums.size();
        for (int i=0; i<size; ++i) {
            while (nums[nums[i]-1] != nums[i]) {
                swap (nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<size; ++i) {
            if (nums[i] != i+1) res.push_back(nums[i]);
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res;
        for (int i=0; i<n; ++i) {
            nums[(nums[i]-1)%n] += n;
        }
        for (int i=0; i<n; ++i) {
            if (nums[i] > 2*n) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};