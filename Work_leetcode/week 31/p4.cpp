// By lovellp
class Solution {
private:
    int m, n, N, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    const int lc = 1e9 + 7;
    bool check(int i, int j) {return i >= m || j >= n || i < 0 || j < 0;}
public:
    int findPaths(int m, int n, int N, int i, int j) {
        this->m = m, this->n = n, this->N = N;
        vector<vector<int>> dp(m * n, vector<int>(N, -1));
        return solve(i, j, N, dp, 0);
    }
    int solve(int i, int j, int step, vector<vector<int>>& dp, int ans) {
        if (check(i, j) || step == 0) return check(i, j) ? 1: 0;
        if (dp[i*n + j][step-1] == -1) {
            for (int k=0; k<4; ++k) ans = (ans + solve(i + dx[k], j + dy[k], step-1, dp, 0) % lc) % lc;
            dp[i*n + j][step-1] = ans;
        }
        return dp[i*n + j][step-1];
    }
};