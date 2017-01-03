class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;
        assert(n <= 1e5);
        int ans = 1, now = 1, counts = 2;
        queue<int> q;
        for (int i=4; i<=n;) {
            if (counts == 0) {
                counts = q.front();
                q.pop();
                now = now==1 ? 2 : 1;
            } else {
                --counts;
                if (now == 1) ++ ans;
                q.push(now);
                ++i;
            }
        }
        return ans;
    }
};