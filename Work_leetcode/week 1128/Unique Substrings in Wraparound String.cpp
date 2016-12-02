class Solution {
public:
    int foobar(string p) {
        vector<int> dp(26, 0);
        int n = p.size();
        for (int i=0; i<n;) {
            int j = i + 1;
            while (j < n && (p[j] - 'a') == (p[j-1] - 'a' + 1) % 26) ++j;
            for (int k = i; k < j; ++k) {
                dp[p[k] - 'a'] = max(dp[p[k] - 'a'], j - k);
            }
            i = j;
        }
        int ans = 0;
        for (int i=0; i<26; ++i) {
            ans += dp[i];
        }
        return ans;
    }
};