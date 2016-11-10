class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int size = (int)costs.size();
        if (size == 0) return 0;
        int k = (int)costs[0].size();
        int min1 = -1, min2 = -1; // now row's min index
        for (int i=0; i<size; ++i) {
            int last1 = min1, last2 = min2; // last row's min index
            min1 = -1, min2 = -1;
            for (int j=0; j<k; ++j) {
                if (j != last1) costs[i][j] += last1 < 0 ? 0 : costs[i-1][last1];
                else costs[i][j] += last2 < 0 ? 0 : costs[i-1][last2];
                if (min1 < 0 || costs[i][j] < costs[i][min1]) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 < 0 || costs[i][j] < costs[i][min2]) {
                    min2 = j;
                }
            }
        }
        return costs[size-1][min1];
    }
};