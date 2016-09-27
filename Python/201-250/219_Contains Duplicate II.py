class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        numsDict=dict()
        for i in range(len(nums)):
            index=numsDict.get(nums[i])
            if(index>=0 and i-index<=k):
                return True
            numsDict[nums[i]]=i
        return False

                
        