class Solution {
private:
    int m; // line num
    int n; // column num
    const vector<int> dx = {0,0,1,-1};
    const vector<int> dy = {1,-1,0,0};
    string ans = "";
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = (int)maze.size();
        n = m == 0 ? 0 : (int)maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(maze, visited, ball, hole);
        return ans.empty() : "impossible" : ans;
    }
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int>& ball, vector<int>& hole) {
        int i = ball[0], j = ball[1];
        if (canEnd(i, j)) {
            
        }
        if (visited[i][j]) return false;
        visited[i][j] = true;
        // four directions
        for (int t=0; t<4; ++t) {
            int newx = dx[t] + i;
            int newy = dy[t] + j;
            if (check(maze, newx, newy)) continue; // can't go to border
            // find the stop position
            while (!check(maze, newx, newy)) {
                newx = newx + dx[t];
                newy = newy + dy[t];
            }
            newx = newx - dx[t];
            newy = newy - dy[t];
            vector<int> nextVisit = {newx, newy};
            if (dfs(maze, visited, nextVisit, destination)) return true;
        } 
        return false;
    }
    bool canEnd(int i, int j) {
        if (i == )
    }
    bool check(vector<vector<int>>&maze, int i, int j) {
        return i < 0 || i >= m || j < 0 || j >=n || maze[i][j];
    }
};