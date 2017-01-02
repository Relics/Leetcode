class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        vector<bool> visited(9, false);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                dfs(i, j, 0, m, n, visited, ans);
            }
        }
        return ans;
    }
    void dfs(int i, int j, int used, int m, int n, vector<bool>& visited, int& ans) {
        if (i > 2 || i < 0 || j > 2 || j < 0) return;
        if (used >= n) return;
        int index = i*3 + j;
        if (!visited[index]) {
            visited[index] = true;
            ++used;
            if (used >= m && used <= n) ++ans;
            // one move
            dfs(i-1, j, used, m, n, visited, ans);
            dfs(i+1, j, used, m, n, visited, ans);
            dfs(i, j-1, used, m, n, visited, ans);
            dfs(i, j+1, used, m, n, visited, ans);
            dfs(i-1, j-1, used, m, n, visited, ans);
            dfs(i-1, j+1, used, m, n, visited, ans);
            dfs(i+1, j-1, used, m, n, visited, ans);
            dfs(i+1, j+1, used, m, n, visited, ans);
            // jump
            dfs(i+1, j+2, used, m, n, visited, ans);
            dfs(i+2, j+1, used, m, n, visited, ans);
            dfs(i-1, j-2, used, m, n, visited, ans);
            dfs(i-2, j-1, used, m, n, visited, ans);
            dfs(i-1, j+2, used, m, n, visited, ans);
            dfs(i-2, j+1, used, m, n, visited, ans);
            dfs(i+1, j-2, used, m, n, visited, ans);
            dfs(i+2, j-1, used, m, n, visited, ans);
            // line move
            if (j == 0 && visited[i*3 + j+1]) dfs(i, j+2, used, m, n, visited, ans);
            if (i == 0 && visited[(i+1)*3 + j]) dfs(i+2, j, used, m, n, visited, ans);
            if (j == 2 && visited[i*3 + j-1]) dfs(i, j-2, used, m, n, visited, ans);
            if (i == 2 && visited[(i-1)*3 + j]) dfs(i-2, j, used, m, n, visited, ans);
            if (i == 0 && j == 0 && visited[4]) dfs(i+2, j+2, used, m, n, visited, ans);
            if (i == 2 && j == 2 && visited[4]) dfs(i-2, j-2, used, m, n, visited, ans);
            if (i == 0 && j == 2 && visited[4]) dfs(i+2, j-2, used, m, n, visited, ans);
            if (i == 2 && j == 0 && visited[4]) dfs(i-2, j+2, used, m, n, visited, ans);
            visited[index] = false;
        }
    }
};
