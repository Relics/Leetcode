class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int i=0; i<(int)nums.size(); ++i) {
            s.insert(nums[i]);
            if ((int)s.size() > 3) s.erase(s.begin());
        }
        return (int)s.size() < 3 ? *(--s.end()) : *(s.begin());
    }
};