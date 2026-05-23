class Solution {

    using ii = pair<int, int>;
    vector<vector<int>> visited;
    int n, m;
    vector<vector<char>> board_;

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    void dfs(int i, int j) {
        visited[i][j] = 1;
        for (int t = 0; t < 4; t++) {
            int i_ = i+dx[t];
            int j_ = j+dy[t];
            if (isValid(i_, j_) && board_[i_][j_] == 'O' && !visited[i_][j_]) {
                dfs(i_, j_);
            }
        }
    }

    void myFunc(int i, int j) {
        if (board_[i][j] == 'O' && !visited[i][j]) {
            dfs(i, j);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        board_ = board;
        n = board.size();
        m = board[0].size();
        visited.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            myFunc(i, 0);
            myFunc(i, m-1);
        }

        for (int j = 0; j < m; j++) {
            myFunc(0, j);
            myFunc(n-1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
