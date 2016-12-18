class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sum = [0,0,0,0]
        s = 0
        for i in nums:
            s += i
        if s % 4 != 0 or s == 0:
            return False
        subsum = s / 4
        nums.sort(reverse = True)
        return self.helper(0, nums, len(nums), subsum, sum)
    def helper(self, start, nums, len, subsum, sum):
        if start == len:
            for i in sum:
                if i != subsum:
                    return False
            return True
        else:
            subres = False
            for i in xrange(4):
                if sum[i] + nums[start] > subsum: continue
                sum[i] += nums[start]
                if (self.helper(start+1, nums, len, subsum, sum)):
                    subres = True
                    break
                sum[i] -= nums[start]
            return subres
        return True
        
        