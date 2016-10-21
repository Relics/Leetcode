class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int size = (int)nums.size();
        vector <int> myStack;
        myStack.push_back(nums[0]);
        for (int i=1; i<size; ++i) {
            int stackSize = (int)myStack.size();
            if (stackSize == 1) {
                if (nums[i] == myStack[0]) continue;
                if (nums[i] > myStack[0]) {
                    myStack.push_back(myStack[0]);
                    myStack[0] = nums[i];
                } else {
                    myStack.push_back(nums[i]);
                }
            }
            if (stackSize == 2) {
                if (nums[i] == myStack[0] || nums[i] == myStack[1]) continue;
                if (nums[i] > myStack[0]) {
                    myStack.push_back(myStack[1]);
                    myStack[1] = myStack[0];
                    myStack[0] = nums[i];
                } else if (nums[i] > myStack[1]) {
                    myStack.push_back(myStack[1]);
                    myStack[1] = nums[i];
                } else {
                    myStack.push_back(nums[i]);
                }
                
            } else if (stackSize == 3) {
                if (nums[i] == myStack[0] || nums[i] == myStack[1] || nums[i] == myStack[2]) continue;
                if (nums[i] > myStack[0]) {
                    myStack[2] = myStack[1];
                    myStack[1] = myStack[0];
                    myStack[0] = nums[i];
                } else if (nums[i] > myStack[1]) {
                    myStack[2] = myStack[1];
                    myStack[1] = nums[i];
                } else if (nums[i] > myStack[2]){
                    myStack[2] = nums[i];
                }
            }
        }
        return (int)myStack.size() <= 2 ? myStack[0] : myStack[2];
    }
};