class Solution {
public:
    bool canJump(vector<int>& nums) {
        int destination=(int)nums.size()-1;
        int rightest=0;
        for (int i=0; i<destination; ++i){
            if (rightest<i){
                return false;
            }else{
                rightest=max(rightest, nums[i]+i);
            }
        }
        return rightest>=destination;
    }
};