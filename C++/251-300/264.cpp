// TLE edition
class Solution {
private:
    unordered_map<int, bool> dp;
    bool isUgly(int n) {
        if (dp.count(n)) return dp[n];
        bool temp = false;
        if (n % 30 == 0) temp |= isUgly(n / 30);
        if (n % 15 == 0) temp |= isUgly(n / 15);
        if (n % 10 == 0) temp |= isUgly(n / 10);
        if (n % 6 == 0) temp |= isUgly(n / 6);
        if (n % 5 == 0) temp |= isUgly(n / 5);
        if (n % 3 == 0) temp |= isUgly(n / 3);
        if (n % 2 == 0) temp |= isUgly(n / 2);
        
        return dp[n] = temp;
    }
public:
    int nthUglyNumber(int n) {
        dp[0] = false; dp[1] = true; dp[2] = true; dp[3] = true; dp[4] = true; dp[5] = true; dp[6] = true; dp[8] = true; dp[9] =true; dp[10] =true; dp[12] = true; dp[15] = true;
        int counts = 0, i = 1;
        while (true) {
            if (isUgly(i)) {
                ++counts;
                if (counts == n) break;
            }
            ++i;
        }
        return i;
    }
};


// Right Solution: Construct the array

