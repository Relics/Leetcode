class Solution {
public:
    bool canJump(vector<int>& nums) {
        int destination=(int)nums.size()-1;
        for (int i=destination; i>=0; --i){
            if (nums[i]+i >= destination) destination=i;
        }
        return destination<=0;
    }
};