class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = (int) ratings.size();
        if (size == 1) return 1;
        int minimumVal=0;
        vector<int> ans(size, 1);
        for (int i=1; i<size; ++i) {
            if (ratings[i] > ratings[i-1]) ans[i] = ans[i-1] + 1;
        }
        for (int i=size-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) {
                ans[i] = max (ans[i+1] + 1, ans[i]);
            }
            minimumVal += ans[i];
        }
        minimumVal += ans[size-1];
        return minimumVal;
    }
};