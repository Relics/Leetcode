/*
 * created by Stomach_ache
 * Jan. 1, 2017
 * runs in 118ms
 */

class Solution {
public:

    typedef multiset<int>::iterator Iter;
    
    Iter prev(Iter x) {
        return -- x;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        assert(n >= k);
        
        vector<int> tmp(begin(nums), begin(nums) + k);
        sort(begin(tmp), begin(tmp) + k);
        multiset<int> small, big;
        for (int i = 0; i < k / 2; ++ i) {
            small.insert(tmp[i]);
        }
        for (int i = k / 2; i < k; ++ i) {
            big.insert(tmp[i]);
        }
        vector<double> ans;
        int i = k;
        
        do {
            if (k & 1) {
                ans.emplace_back(*begin(big));
            } else {
                ans.emplace_back((*begin(big)) * 0.5 + (*small.rbegin()) * 0.5);
            }
            
            if (i == n) break;
            
            bool flag = false;
            if (small.find(nums[i - k]) != end(small)) {
                flag = true;
                small.erase(small.find(nums[i - k]));
            } else {
                big.erase(big.find(nums[i - k]));
            }
            
            if (flag) {
                small.insert(nums[i]);
            } else {
                big.insert(nums[i]);
            }
            
            if (k > 1 && *small.rbegin() > (*begin(big))) {
                small.insert(*begin(big));
                big.erase(begin(big));
                big.insert(*small.rbegin());
                small.erase(prev(small.end()));
            }
            ++ i;
        } while (i <= n);
        
        return ans;
    }
};