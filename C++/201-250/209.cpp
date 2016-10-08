// solution 1
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minimumLen = 0;
        bool flag = false;
        int size = (int)nums.size();
        int l = 0, r = 0;
        int subTemp = 0;
        while (l<size && r<size) {
            subTemp += nums[r];
            if (subTemp < s) {
                ++r;
            } else {
                if (!flag) {
                    minimumLen = r-l+1;
                    flag = true;
                }
                while (l<=r && l<size && subTemp>=s) {
                    minimumLen = min(minimumLen, r-l+1);
                    subTemp -= nums[l];
                    ++l;
                }
                ++r;
            }
        }
        return minimumLen;
    }
};

// solution 2
// Unlike upper_bound, the value pointed by the iterator returned by this function may also be equivalent to val, and not only greater.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        int size = (int)nums.size();
        vector<int> sum(size+1);
        sum[0] = 0;
        for (int i=0; i<size; ++i) {
            sum[i+1] = sum[i] + nums[i];
        }
        for (int i=0; i<size+1; ++i) {
            int n = lower_bound(sum.begin(), sum.end(), sum[i]+s) - sum.begin();
            if (n == size+1) break;
            minLen = min(minLen, n-i);
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
