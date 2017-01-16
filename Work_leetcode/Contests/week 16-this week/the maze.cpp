class Solution {
private:
    int m; // line num
    int n; // column num
    const vector<int> dx = {0,0,1,-1};
    const vector<int> dy = {1,-1,0,0};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = (int)maze.size();
        n = m == 0 ? 0 : (int)maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(maze, visited, start, destination);
    }
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int>& start, vector<int>& destination) {
        int i = start[0], j = start[1];
        if (i == destination[0] && j == destination[1]) return true;
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
    bool check(vector<vector<int>>&maze, int i, int j) {
        return i < 0 || i >= m || j < 0 || j >=n || maze[i][j];
    }
};