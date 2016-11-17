class Solution {
public:
    int islandPerimeter(vector<vector<int>>& map) {
        int m = map.size(), n = m==0 ? 0 : map[0].size();
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (map[i][j] != 0) {
                    int subans = 4;
                    if (i>0 && map[i-1][j]) subans -= 1;
                    if (j>0 && map[i][j-1]) subans -= 1;
                    if (i<m-1 && map[i+1][j]) subans -= 1;
                    if (j<n-1 && map[i][j+1]) subans -= 1;
                    ans += subans;
                }
            }
        }
        return ans;
    }
};