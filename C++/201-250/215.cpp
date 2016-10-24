class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);
        int storeIndex = left;
        for (int i=left; i<=right-1; ++i) {
            if (nums[i] < pivotValue) {
                swap(nums[i], nums[storeIndex]);
                ++storeIndex;
            }
        }
        swap(nums[right], nums[storeIndex]);
        return storeIndex;
    }
    int select(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);
        if (k == pivotIndex) {
            return nums[k];
        } else if (k < pivotIndex) {
            return select(nums, left, pivotIndex-1, k);
        } else {
            return select(nums, pivotIndex+1, right, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return select(nums, 0, (int)nums.size()-1, (int)nums.size()-k);
    }
};
