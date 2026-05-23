class Solution {

    int n;
    int m;
    using ii = pair<int, int>;
    vector<vector<int>> dist;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        queue<ii> q;
        dist.assign(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                
            }
        }
        while (!q.empty()) {
            ii v = q.front();
            q.pop();
            for (int t = 0; t < 4; t++) {
                int i_ = v.first + dx[t];
                int j_ = v.second + dy[t];
                if (isValid(i_, j_) && grid[i_][j_] != 0 && dist[i_][j_] == 1e9) {
                    dist[i_][j_] = dist[v.first][v.second] + 1;
                    q.push({i_, j_});
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    answer = max(answer, dist[i][j]);
                }
            }
        }
        if (answer == 1e9) {
            return -1;
        }
        return answer;
    }
};
