class Solution {
public:
    int m; // line num
    int n; // column num
    const vector<int> dx = {0,0,1,-1};
    const vector<int> dy = {1,-1,0,0};
    const vector<string> ds = {"r","l","u","d"};
    string ans = "";
    int anslen = INT_MAX;

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = (int)maze.size();
        n = m == 0 ? 0 : (int)maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(maze, visited, ball, hole, "", 0);
        return ans == "" ? "impossible" : ans;
    }
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int>& ball, vector<int>& hole, string temp, int length) {
        int i = ball[0], j = ball[1];
        int steps = canEnd(i, j, maze, hole) + length;
        if (steps != -1) {
            if (steps < anslen) {
                anslen = steps;
                ans = temp;
                return true;
            }
            if (steps == anslen) {
                if (ans > temp) {
                    ans = temp;
                }
                return true;
            }
        }
        if (visited[i][j]) return false;
        visited[i][j] = true;
        // four directions
        for (int t=0; t<4; ++t) {
            int newlength = length;
            int newx = dx[t] + i;
            int newy = dy[t] + j;
            if (check(maze, newx, newy)) continue; // can't go to border
            // find the stop position
            while (!check(maze, newx, newy)) {
                newx = newx + dx[t];
                newy = newy + dy[t];
                ++newlength;
            }
            newx = newx - dx[t];
            newy = newy - dy[t];
            --newlength;
            vector<int> nextVisit = {newx, newy};
            if (dfs(maze, visited, nextVisit, hole, temp+ds[t], newlength)) return true;
        } 
        return false;
    }
    int canEnd(int i, int j, vector<vector<int>>& maze, vector<int>& hole) {
        int steps = 0;
        int hx = hole[0], hy = hole[1];
        if (hx == i && hy == j) return 0;
        if (hx != i && hy != j) return -1;
        if (hx == i) {
            if (hy > j) {
                while (j < n && maze[i][j] != 1 && j != hy) {
                    ++steps;
                    ++j;
                }
                if (j == hy) return steps;
            } else {
                while (j>=0 && maze[i][j] != 1 && j != hy) {
                    ++steps;
                    --j;
                }
                if (j == hy) return steps;
            }
        } else {
            if (hx > i) {
                while (i < m && maze[i][j] != 1 && i != hx)     {
                    ++steps;
                    ++i;
                }
                if (i == hx) return steps;
            } else {
                while (i >=0 && maze[i][j] != 1 && i != hx) {
                    ++steps;
                    --i;
                }
                if (i == hx) return steps;
            }
        }
        return -1;
    }
    bool check(vector<vector<int>>&maze, int i, int j) {
        return i < 0 || i >= m || j < 0 || j >=n || maze[i][j];
    }
};