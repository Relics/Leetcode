class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m << i;
    }
};

// 011 - 3
// 100 - 4
// 101 - 5
// 110 - 6
// 111 - 7
// 1000 - 8
