class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int ans = 0, l1 = (int)low.size(), l2 = (int)high.size();
        if (l1 == 0 || l2 == 0 || l1 > l2) return 0;
        helper("", low, high, ans);
        helper("8", low, high, ans);
        helper("1", low, high, ans);
        helper("0", low, high, ans);
        return ans;
    }
    void helper(string mid, string low, string high, int & ans) {
        int midLen = (int)mid.size(), lowLen = (int)low.size(), highLen = (int)high.size();
        if (midLen > highLen) return;
        for (int i=0; i<1; ++i) {
            if (mid[0] == '0' && midLen > 1) continue;
            if (midLen < lowLen) continue;
            if (midLen == lowLen && mid < low) continue;
            if (midLen == highLen && mid > high) continue;
            ++ ans;
        }
        helper("0" + mid + "0", low, high, ans);
        helper("6" + mid + "9", low, high, ans);
        helper("1" + mid + "1", low, high, ans);
        helper("9" + mid + "6", low, high, ans); 
        helper("8" + mid + "8", low, high, ans);
    }
};