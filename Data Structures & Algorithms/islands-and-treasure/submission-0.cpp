class Solution {
    using ii = pair<int, int>;
    int n, m;

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != -1);
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<ii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            ii p = q.front();
            q.pop();
            for (int t = 0; t < 4; t++) {
                int i_ = p.first + dx[t];
                int j_ = p.second + dy[t];
                if (isValid(i_, j_, grid) && grid[i_][j_] == INT_MAX) {
                    grid[i_][j_] = grid[p.first][p.second] + 1;
                    q.push({i_, j_});
                }
            }
        }

    }
};
