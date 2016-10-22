class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        int i = 0, j = n-1;
        while (i<=m-1 && j>=0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --j;
            else {
                ++i;
            }
        }
        return false;
    }
};