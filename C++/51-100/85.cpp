class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = (int)matrix.size(), n = m ? (int)matrix[0].size() : 0;
        if (n == 0) return 0;
        vector<int> heights(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] = heights[j] + 1;
                } else {
                    heights[j] = 0;
                }
            }
            int maxRectangle = findMaxRectangle(heights);
            ans = max(ans, maxRectangle);
        }
        return ans;
    }
    int findMaxRectangle(vector<int>& heights) {
        stack<int> indexs;
        int size = (int)heights.size();
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (indexs.empty() || heights[indexs.top()] <= heights[i]) {
                indexs.push(i);
            } else {
                while (!indexs.empty() && heights[indexs.top()] > heights[i]) {
                    int heightIndex = indexs.top();
                    indexs.pop();
                    int width = indexs.empty() ? i : i - (indexs.top() + 1);
                    int area = width * heights[heightIndex];
                    ans = max(ans, area);
                }
                indexs.push(i);
            }
        }
        return ans;
    }
};