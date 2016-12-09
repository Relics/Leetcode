// By lovellp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101] = {0};
        assert(m <= 100);
        assert(n <= 100);
        for (string str : strs) {
            int z = 0, o = 0;
            for (char ch : str) {
                if (ch == '1') ++o;
                else ++z;
            }
            for (int i = m; i >= z; --i) {
                for (int j = n; j >= o; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-z][j-o] + 1);
                }
            }
        }
        return dp[m][n];
    }
};