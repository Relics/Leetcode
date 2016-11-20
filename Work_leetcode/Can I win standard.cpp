class Solution {
typedef long long ll;
    public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        ll n = maxChoosableInteger, m = desiredTotal;
        ll sum = (1 + n) * n / 2;
        if (sum < m) return false;

        dp[(1<<maxChoosableInteger) - 1] = true;
        for (int mask = (1<<maxChoosableInteger) - 2; mask >= 0; -- mask) {
            int s = 0;
            for (int i = 0; i < maxChoosableInteger; ++ i) if ((mask & (1<<i))) s += i + 1;
            for (int i = 0; i < maxChoosableInteger; ++ i) if (!(mask & (1<<i))) {
                if (s + i + 1 >= desiredTotal) {
                    dp[mask] = true;
                    break;
                } else if (!dp[mask | (1<<i)]) {
                    dp[mask] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

private:
    bool dp[1<<20];
};