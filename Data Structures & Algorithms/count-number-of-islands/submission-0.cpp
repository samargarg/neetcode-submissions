class Solution {
    int islands;
    int n;
    int m;
    vector<vector<bool>> visited;
    vector<vector<char>> grid_;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m && (grid_[i][j] == '1'));
    }

    void dfs(int i, int j) {
        visited[i][j] = true;
        for (int t = 0; t < 4; t++) {
            int i_ = i+dx[t];
            int j_ = j+dy[t];
            if (isValid(i_, j_) && !visited[i_][j_]) {
                dfs(i_, j_);
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        grid_ = grid;
        islands = 0;
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(i, j);
                }
            }
        }
        return islands;
    }
};
