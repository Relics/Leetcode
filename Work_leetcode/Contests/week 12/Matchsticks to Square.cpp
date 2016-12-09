class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for (auto num : nums) sum += num;
        if (sum % 4 != 0) return false;
        int length = sum / 4;
        sort(nums.rbegin(), nums.rend());
    	if (nums[0] > length) return false;
    	vector<int> sum(size);
    	sum[size-1] = nums[size-1];
    	for (int i=size-2; i>=0; --i) {
    		sum[i] = sums[i+1] + nums[i];
    	}
    	for (int i=0; i<size-3; ++i) {
    		
    	}
    	return false;
    }
};