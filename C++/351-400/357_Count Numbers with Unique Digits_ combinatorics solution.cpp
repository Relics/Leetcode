class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        else if (n>11) n=10;
        int temp=1;
        int ans=10;
        for (int i=1; i<=n; ++i){
            if (i == 1) temp = 9;
            else temp *= 11-i;
            if (i > 1) ans += temp;
        }
        return ans;
    }
};