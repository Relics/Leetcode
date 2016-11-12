class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = (int)A.size(), n = (int)B[0].size();
        int t = (int)A[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for (int i=0; i<m; ++i) {
            for (int k=0; k<t; ++k) {
                if (A[i][k] != 0) {
                    for (int j=0; j<n; ++j) {
                        if (B[k][j] != 0) {
                            ans[i][j] += A[i][k] * B[k][j];
                        }    
                    }
                }
            }
        }
        return ans;
    }
};