class Solution {

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    vector<vector<int>> grid_;

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    vector<vector<int>> dist;
    int n;
    void dijakstras(int i, int j) {
        dist[i][j] = grid_[i][j];
        set<vector<int>> s;
        s.insert(vector<int>{dist[i][j], i, j});
        while (!s.empty()) {
            int total_time = (*s.begin())[0];
            int i = (*s.begin())[1];
            int j = (*s.begin())[2];
            s.erase(s.begin());
            if (total_time != dist[i][j]) {
                continue;
            }
            for (int t = 0; t < 4; t++) {
                int i_ = i+dx[t];
                int j_ = j+dy[t];
                if (isValid(i_, j_) && dist[i_][j_] == 1e9) {
                    dist[i_][j_] = max(dist[i][j], grid_[i_][j_]);
                    s.insert(vector<int>{dist[i_][j_], i_, j_});
                }
            }
        }
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        grid_ = grid;
        n = grid.size();
        dist.resize(n, vector<int>(n, 1e9));
        dijakstras(0, 0);
        return dist[n-1][n-1];
    }
};
