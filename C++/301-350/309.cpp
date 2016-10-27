// Refering: https://discuss.leetcode.com/topic/30431/easiest-java-solution-with-explanations/2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ((int)prices.size() == 0) return 0;
        int s0 = 0, s1 = 0, s2 = 0, b0 = -prices[0], b1 = 0;
        int size = (int)prices.size();
        for (int i = 1; i < size; ++i) {
            s2 = max(s1, b0 + prices[i]);
            b1 = max(b0, s0 - prices[i]);
            s0 = s1; s1 = s2;
            b0 = b1;
        }
        return s2;
    }
};