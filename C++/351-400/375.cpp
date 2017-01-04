class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] from i to j : cost is ?
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return find(dp, 1, n);
    }
    int find(vector<vector<int>>& dp, int start, int end) {
        if (start >= end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        for (int i=start; i<=end; ++i) {
            int a = find(dp, start, i-1);
            int b = find(dp, i+1, end);
            int c = max(a, b) + i;
            if (dp[start][end] == -1) {
                dp[start][end] = c;
            } else {
                dp[start][end] = min(dp[start][end], c);
            }
        }
        return dp[start][end];
    }
};