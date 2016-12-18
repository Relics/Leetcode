public class Solution {
    public boolean makesquare(int[] nums) {
        int[] sum = new int[4];
        sum[0] = sum[1] = sum[2] = sum[3] = 0;
        int s = 0;
        for (int num : nums) s += num;
        if (s % 4 != 0 || s == 0) return false;
        int subsum = s / 4;
        Arrays.sort(nums);
        return helper(nums.length - 1, nums, subsum, sum);
    }
    public boolean helper(int start, int[] nums, int subsum, int[] sum) {
        if (start == -1) {
            for (int i : sum) {
                if (i != subsum) return false;
            }
            return true;
        } else {
            boolean subres = false;
            for (int i=0; i<4; ++i) {
                if (sum[i] + nums[start] > subsum) continue;
                sum[i] += nums[start];
                if (helper(start-1, nums, subsum, sum)) {subres = true; break;}
                sum[i] -= nums[start];
            }
            return subres;
        }
    }
}