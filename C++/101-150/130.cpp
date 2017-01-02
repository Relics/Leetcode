// dfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        int n = m ? (int)board[0].size() : 0;
        for (int i=0; i<n; ++i) {
            dfs(0, i, board, m, n);
            if (m > 1) dfs(m-1, i, board, m, n);
        }
        for (int i=1; i<m-1; ++i) {
            dfs(i, 0, board, m, n);
            if (n > 1) dfs(i, n-1, board, m, n);
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'Y';
        if (i+1 < m-1) dfs(i+1, j, board, m, n);
        if (i-1 >= 1) dfs(i-1, j, board, m, n);
        if (j+1 < n-1) dfs(i, j+1, board, m, n);
        if (j-1 >= 1) dfs(i, j-1, board, m, n);
    }
};

// bfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        int n = m ? (int)board[0].size() : 0;
        for (int i=0; i<n; ++i) {
            if (board[0][i] == 'O') bfs(0, i, board, m, n);
            if (m > 1 && board[m-1][i] == 'O') bfs(m-1, i, board, m, n);
        }
        for (int i=1; i<m-1; ++i) {
            if (board[i][0] == 'O') bfs(i, 0, board, m, n);
            if (n > 1 && board[i][n-1] == 'O') bfs(i, n-1, board, m, n);
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
    void bfs(int i, int j, vector<vector<char>>& board, int m, int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto next = q.front();
            q.pop();
            i = next.first, j = next.second;
            board[i][j] = 'B';
            if (i < m-2 && board[i+1][j] == 'O') {
                board[i+1][j] = 'B'; // Otherwise it will be pushed into the queue again and again
                q.push(make_pair(i+1, j));
            }
            if (i > 1 && board[i-1][j] == 'O') {
                board[i-1][j] = 'B';
                q.push(make_pair(i-1, j));
            }
            if (j < n-2 && board[i][j+1] == 'O') {
                board[i][j+1] = 'B';
                q.push(make_pair(i, j+1));
            }
            if (j > 1 && board[i][j-1] == 'O') {
                board[i][j-1] = 'B';
                q.push(make_pair(i, j-1));
            }
        }
    }
};