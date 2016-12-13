class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // The front will be the biggest one's index [i-(k-1), i]
        int size = (int)nums.size();
        for (int i=0; i<size; ++i) {
            while (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};