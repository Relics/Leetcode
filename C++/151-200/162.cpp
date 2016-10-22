class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = (int)nums.size()-1;
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (mid > 0 && nums[mid] < nums[mid-1]) r = mid-1;
            else if (mid<(int)nums.size()-1 && nums[mid] < nums[mid+1]) l = mid+1;
            else {
                return mid;
            }
        }
        return nums[l] > nums[r] ? l : r;
    }
};