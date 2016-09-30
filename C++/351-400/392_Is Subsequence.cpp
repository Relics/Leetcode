class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        for (; i < (int)s.size(), j < (int)t.size(); ++j) {
            if (s[i] == t[j]) {
                ++ i;
            }
        }
        return i== (int)s.size();
    }
};