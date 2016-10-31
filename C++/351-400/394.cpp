class Solution {
public:
    string dfs(string s, int& k) {
        string ans = "";
        int counts = 0;
        int size = (int)s.size();
        while (k < size) {
            if (isdigit(s[k])) {
                counts = counts * 10 + (s[k++] - '0');
            } else if (s[k] == '[') {
                string subans = dfs(s, ++k);
                // here is the advice,
                // while (counts>0 && counts--) will be better than while (counts--)
                while (counts>0 && counts--) {
                    ans += subans;
                }
                counts = 0;
            } else if (s[k] == ']') {
                ++k;
                return ans;
            } else {
                ans += s[k++];
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int k = 0;
        return dfs(s, k);
    }
};