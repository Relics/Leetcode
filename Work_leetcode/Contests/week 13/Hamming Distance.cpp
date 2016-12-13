// By lovellp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int temp = x ^ y;
        while (temp) {
            if (temp & 1) ++ans;
            temp >>= 1;
        }
        return ans;
    }
};